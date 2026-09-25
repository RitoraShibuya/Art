#include "processing.h"

struct ThreadParticle {
    Vector2 pos;
    Vector2 prev_pos;
    double angle;
    double radius;
    double hue;
};

std::vector<ThreadParticle> particles;
int frame_count = 0;
bool swirl_active = false;

void hsbToRgb( double h, double s, double v, double& r, double& g, double& b );

void setup( ) {
    size( 600, 600 );
    colorMode( HSB, 360, 1, 1 );
    noFill( );
    for ( int i = 0; i < 250; ++i ) {
        ThreadParticle p;
        p.pos = Vector2( getWidth( ) / 2 + random( -100, 100 ), getHeight( ) / 2 + random( -100, 100 ) );
        p.prev_pos = p.pos;
        p.angle = random( PI2 );
        p.radius = random( 1.0, 2.5 );
        p.hue = fmod( random( 360 ), 360 );
        particles.push_back( p );
    }
}

void draw( ) {
    frame_count++;
    background( 0, 5 );

    double mouse_strength = ( getMouseX() - getWidth( ) / 2.0 ) / ( double )getWidth( );

    for ( ThreadParticle& p : particles ) {
        p.prev_pos = p.pos;

        double curl = sin( p.angle + frame_count * 0.01 + p.radius ) * 0.5;
        double twist = swirl_active ? sin( frame_count * 0.2 + p.radius * 10.0 ) * 3.0 : 0.0;

        p.angle += 0.05 * ( 1 + mouse_strength * 2.0 ) + twist * 0.01;
        p.radius += 0.2;

        int p_x = frame_count % 240 < 75 ? cos(p.angle) * p.radius * 0.3 : sin(p.angle)* p.radius * 0.3;
        int p_y = frame_count % 180 < 75 ? sin(p.angle) * p.radius * 0.3 : cos(p.angle) * p.radius * 0.3;

        p.pos.x += p_x;
        p.pos.y += p_y;

        if ( p.pos.x < 0 || p.pos.x > getWidth( ) || p.pos.y < 0 || p.pos.y > getHeight( ) ) {
            p.pos = Vector2( getWidth( ) / 2, getHeight( ) / 2 );
            p.radius = random( 1.0, 2.5 );
            p.angle = random( PI2 );
        }

        double r, g, b;
        hsbToRgb( p.hue, 0.5, 1.0, r, g, b );
        stroke( r, g, b, 50 );
        strokeWeight(5);
        line( p.prev_pos, p.pos );
    }

    if ( swirl_active && frame_count % 60 == 0 ) {
        swirl_active = false;
    }
}

void mousePressed( ) {
    swirl_active = true;
}

void hsbToRgb( double h, double s, double v, double& r, double& g, double& b ) {
    h = fmod( h, 360.0 );
    double c = v * s;
    double x = c * ( 1 - fabs( fmod( h / 60.0, 2 ) - 1 ) );
    double m = v - c;

    double rr = 0;
    double gg = 0;
    double bb = 0;
    if ( h < 60 ) {
        rr = c; gg = x; bb = 0; 
    } else if ( h < 120 ) { 
        rr = x; gg = c; bb = 0; 
    } else if ( h < 180 ) { 
        rr = 0; gg = c; bb = x; 
    } else if ( h < 240 ) { 
        rr = 0; gg = x; bb = c; 
    } else if ( h < 300 ) { 
        rr = x; gg = 0; bb = c; 
    } else { 
        rr = c; gg = 0; bb = x; 
    }

    r = ( rr + m ) * 255.0;
    g = ( gg + m ) * 255.0;
    b = ( bb + m ) * 255.0;
}
