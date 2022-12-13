#pragma once

#include "NIDefines.h"

namespace NI {
	struct PixelFormat {
		enum struct Format : int {
			RGB = 0,
			RGBA = 1,
			PALETTE = 2,
			PALETTE_ALPHA = 3,
			BGR = 4,
			BGRA = 5,
			COMPRESS1 = 6,
			COMPRESS3 = 7,
			COMPRESS5 = 8,
			RGB24_NONINTERLEAVED = 9,
			BUMP = 10,
			BUMPLUMA = 11
		};

		Format format;
		unsigned int channelMasks[4];
		unsigned int bitsPerPixel;
		unsigned int compareBits[2];
	};
	static_assert(sizeof(PixelFormat) == 0x20, "NI::PixelFormat failed size validation");
}
