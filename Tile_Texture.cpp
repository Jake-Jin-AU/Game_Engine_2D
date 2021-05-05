#include "Tile_Texture.h"

Tile_Texture::Tile_Texture(const std::string& id, const std::string& path, SDL_Renderer* renderer, int frame_count)
: Texture(id, path, renderer)
{
	_frame_count	= frame_count;
	_frame_no = 0;
}

Tile_Texture::~Tile_Texture()
{
}

void Tile_Texture::set_frame(const int& frame_no)
{
	_frame_no = frame_no;
}

void Tile_Texture::render(SDL_Renderer* renderer, SDL_Rect*, SDL_Rect* destination, const SDL_RendererFlip& flip) const
{
	// Get texture width and height
	int texture_width = 0;
	int texture_height = 0;
	const int query_texture_result = SDL_QueryTexture(get_texture(), nullptr, nullptr, &texture_width, &texture_height);

	const int frame_width = texture_width / _frame_count;

	// Calculate clipping rect
	SDL_Rect frame_clip;
	frame_clip.x = _frame_no * frame_width;
	frame_clip.y = 0;
	frame_clip.w = frame_width;
	frame_clip.h = texture_height;

	Texture::render(renderer, &frame_clip, destination, flip);
}
