#pragma once
#include <iostream>

class Asset
{
public:
	Asset(const std::string& id);
	~Asset();

	const std::string& get_id() const;
	const int& get_pixel_width() const;
	const int& get_pixel_height() const;

protected:
	int			_pixel_width;
	int			_pixel_height;

private:
	std::string _id;
};

