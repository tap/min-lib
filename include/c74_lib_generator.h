/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once


namespace c74 {
namespace min {
namespace lib {

    /// Defines several functions for use with <a href="http://en.cppreference.com/w/cpp/algorithm/generate">std::generate</a> to fill vectors with common shapes used in computer sound.

	namespace generator {


        /// Generates a line from -1 to 1 with consistent slope
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        class ramp {
        public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

            ramp (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

            T operator()() {
                ++m_current;
                return ( T( ( fmod(m_current * m_cycle_count / m_cycle_size, 1.0) * 2.0 ) - 1.0));
            }

        private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
        };


        /// Generates an ideal sawtooth waveform from -1 to 1. Not anti-aliased.
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        using sawtooth = generator::ramp<T>;


        /// Generates a line from 0 to 1 with consistent slope
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

		template <typename T>
		class ramp_unipolar {
		public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

			ramp_unipolar (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
			{
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

			T operator()() {
				++m_current;
				return ( T(fmod(m_current * m_cycle_count / m_cycle_size, 1.0)));
			}

		private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
		};


        /// Generates an ideal sawtooth waveform from 0 to 1. Not anti-aliased.
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        using sawtooth_unipolar = generator::ramp_unipolar<T>;


        /// Generates a sine wave constrained between -1 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

		template <typename T>
		class sine {
		public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

			sine (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

			T operator()() {
				++m_current;
				auto output = std::sin(m_current*m_cycle_count * (2.0 * M_PI) / m_cycle_size);
				return T(output);
			}

		private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
		};


        /// Generates a sine wave constrained between 0 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        class sine_unipolar {
        public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

           sine_unipolar (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

            T operator()() {
                ++m_current;
                auto output = 0.5 * std::sin(m_current*m_cycle_count * (2.0 * M_PI) / m_cycle_size);
                return T(output) + 0.5;
            }

        private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
        };


        /// Generates a cosine wave constrained between -1 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        class cosine {
        public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

            cosine (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

           T operator()() {
                ++m_current;
                auto output = std::cos(m_current*m_cycle_count * (2.0 * M_PI) / m_cycle_size);
                return T(output);
            }

        private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
        };


        /// Generates a cosine wave constrained between 0 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        class cosine_unipolar {
        public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

            cosine_unipolar (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

           T operator()() {
                ++m_current;
                auto output = 0.5 + 0.5 * std::cos(m_current*m_cycle_count * (2.0 * M_PI) / m_cycle_size);
                return T(output);
            }

        private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
        };


        /// Generates a triangle wave constrained between -1 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

		template <typename T>
		class triangle {
		public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

			triangle (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

			T operator()() {
				T out = 0.0;
				++m_current;
                
                auto delta = fmod(m_current * m_cycle_count / m_cycle_size, 1.0) ;

				if (delta <= 0.25)
					out = delta / 0.25;
				else if (delta >= 0.75)
					out = -1.0 + (delta - 0.75) / 0.25;
				else
					out = 1.0 - (delta - 0.25) / 0.25;
				return out;
			}

		private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
		};


        /// Generates a triangle wave constrained between 0 to 1
        /// @tparam T       render output as this datatype. algorithm was designed to assume the use of floating point.

        template <typename T>
        class triangle_unipolar {
        public:

			/// Create an instance of a generator to calculate an output with N points.
			/// @param	size	The number of points over which the generator will produce a function.
			///	@param	count	number of cycles of the wave to generate across the vector. default is 1.

           triangle_unipolar (size_t size, double count = 1.0)
			: m_cycle_size	{ size	}
			, m_cycle_count	{ count }
			{
                //TODO: we need way to protect against zero. static_assert did not work.
            }


			/// Called by std::generate to produce the next value in the series to produce this function.
			///	@return	The next value in the series.

           T operator()() {
                T out = 0.0;
                ++m_current;

               auto delta = fmod(m_current * m_cycle_count / m_cycle_size, 1.0) ;
               
               if (delta <= 0.25)
                   out = delta / 0.5;
               else if (delta >= 0.75)
                   out = 1.0 + (delta - 1.5) / 0.5;
               else
                   out = -2.0 - (delta - 1.5) / 0.5;
               return out + 0.5;
            }

        private:
			int		m_current { -1 };
			size_t	m_cycle_size;
			number	m_cycle_count;
        };

	} // namespace generator
}}}  // namespace c74::min::lib
