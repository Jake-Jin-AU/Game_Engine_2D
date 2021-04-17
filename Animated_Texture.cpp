#include "Animated_Texture.h"
#include "Texture.h"

Animated_Texture::Animated_Texture(const std::string id, const std::string path, SDL_Renderer* renderer, int frame_count, Uint32 frame_duration_milliseconds)
	: Texture(id, path, renderer)
{
	// Initialise an animated texture
	_frame_count					= frame_count;
	_current_frame					= 0;
	_frame_duration_milliseconds	= frame_duration_milliseconds;
	_total_time_milliseconds		= frame_duration_milliseconds;
}

Animated_Texture::~Animated_Texture()
{
}

void Animated_Texture::update_frame(const Uint32& milliseconds_to_simulate)
{
	_total_time_milliseconds += milliseconds_to_simulate;
	_current_frame = (_total_time_milliseconds / _frame_duration_milliseconds) % _frame_count;
}

void Animated_Texture::render(SDL_Renderer* renderer, SDL_Rect*, SDL_Rect* destination, const SDL_RendererFlip& flip) const
{
	// Get texture width and height
	int texture_width	= 0;
	int texture_height	= 0;
	const int query_texture_result = SDL_QueryTexture(get_texture(), nullptr, nullptr, &texture_width, &texture_height);

	// Calculate a frame width
	const int frame_width = texture_width / _frame_count;

	// Calculate clipping rect
	SDL_Rect frame_clip;
	frame_clip.x = _current_frame * frame_width;
	frame_clip.y = 0;
	frame_clip.w = frame_width;
	frame_clip.h = texture_height;

	Texture::render(renderer, &frame_clip, destination, flip);

}
