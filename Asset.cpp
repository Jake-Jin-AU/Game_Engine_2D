#include "Asset.h"

Asset::Asset(const std::string& id)
{
	_id = id;
}

Asset::~Asset()
{
}

const std::string& Asset::get_id() const
{
	return _id;
}

const int& Asset::get_pixel_width() const
{
	return _pixel_width;
}

const int& Asset::get_pixel_height() const
{
	return _pixel_height;
}
