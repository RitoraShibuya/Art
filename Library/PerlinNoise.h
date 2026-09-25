#pragma once

#include <algorithm>
#include <random>
#include <array>

class PerlinNoise {
public:
	constexpr PerlinNoise( ) = default;
	explicit PerlinNoise( const std::uint_fast32_t seed_ );
	void setSeed( const std::uint_fast32_t seed_ );
	template <typename... Args>
	double noise( const Args... args_ ) const noexcept {
		return this->setNoise( args_... ) * 0.5 + 0.5;
	}
	template <typename... Args>
	double octaveNoise( const std::size_t octaves_, const Args... args_ ) const noexcept {
		return this->setOctaveNoise( octaves_, args_... ) * 0.5 + 0.5;
	}
private:
	using Pint = std::uint_fast8_t;
private:
	constexpr double getFade( const double t_ ) const noexcept;
	constexpr double getLerp( const double t_, const double a_, const double b_ ) const noexcept;
	constexpr double makeGrad( const Pint hash_, const double u_, const double v_ ) const noexcept;
	constexpr double makeGrad( const Pint hash_, const double x_, const double y_, const double z_ ) const noexcept;
	constexpr double getGrad( const Pint hash_, const double x_, const double y_, const double z_ ) const noexcept;
	double setNoise( double x_ = 0.0, double y_ = 0.0, double z_ = 0.0 ) const noexcept;
	double setOctaveNoise( const std::size_t octaves_, double x_ ) const noexcept;
	double setOctaveNoise( const std::size_t octaves_, double x_, double y_ ) const noexcept;
	double setOctaveNoise( const std::size_t octaves_, double x_, double y_, double z_ ) const noexcept;
private:
	std::array<Pint, 512> p { {} };
};
