#pragma once

////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
//
// Copyright (c) 2017 Nicholas Frechette & Animation Compression Library contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include "acl/core/memory.h"
#include "acl/math/vector4_32.h"

#include <cstdint>

namespace acl
{
	// TODO: get an official L3 cache size
	constexpr size_t CACHE_FLUSH_BUFFER_BYTES = 20 * 1024 * 1024;

	inline Vector4_32* allocate_cache_flush_buffer(Allocator& allocator) { return allocate_type_array<Vector4_32>(allocator, CACHE_FLUSH_BUFFER_BYTES / sizeof(Vector4_32)); }
	inline void deallocate_cache_flush_buffer(Allocator& allocator, Vector4_32* buffer) { deallocate_type_array(allocator, buffer, CACHE_FLUSH_BUFFER_BYTES / sizeof(Vector4_32)); }

	inline void flush_cache(Vector4_32* buffer)
	{
		for (size_t i = 0; i < CACHE_FLUSH_BUFFER_BYTES / sizeof(Vector4_32); ++i)
			buffer[i] = vector_add(buffer[i], vector_set(1.0f));
	}
}
