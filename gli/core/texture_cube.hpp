///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/texture_cube.hpp
/// @date 2011-04-06 / 2013-01-11
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_TEXTURE_CUBE_INCLUDED
#define GLI_CORE_TEXTURE_CUBE_INCLUDED

#include "texture2d.hpp"

namespace gli
{
	class textureCube
	{
	public:
		typedef detail::storage::texcoord2_type dimensions_type;
		typedef detail::storage::texcoord2_type texcoord_type;
		typedef detail::storage::size_type size_type;
		typedef detail::storage::format_type format_type;

	public:
		textureCube();

		/// Allocate a new storage constructor
		explicit textureCube(
			size_type const & Faces,
			size_type const & Levels,
			format_type const & Format,
			dimensions_type const & Dimensions);

		/// Reference an exiting storage constructor
		explicit textureCube(
			format_type const & Format,
			shared_ptr<detail::storage> const & Storage,
			detail::view const & View);

		~textureCube();

		texture2D const & operator[] (face const & Face) const;

		bool empty() const;
		size_type size() const;
		dimensions_type dimensions() const;
		size_type levels() const;
		size_type faces() const;
		format_type format() const;

		void * data();
		void const * const data() const;

		template <typename genType>
		genType * data();
		template <typename genType>
		genType const * const data() const;

	private:
		shared_ptr<detail::storage> Storage;
		detail::view const View;
		format_type const Format;
	};

}//namespace gli

#include "texture_cube.inl"

#endif//GLI_CORE_TEXTURE_CUBE_INCLUDED
