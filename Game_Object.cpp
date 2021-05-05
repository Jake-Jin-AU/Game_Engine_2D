#include "Game_Object.h"

Game_Object::Game_Object(const std::string& id, const std::string& texture_id, const Vector_2D& pos, const Layer layer)
    : _translation(pos.get_x(), pos.get_y()), _velocity(0, 0), _circle_collider(nullptr), _rect_collider(nullptr), _is_affected_by_gravity(false), _is_ground(false)
{
    _id         = id;
    _texture_id = texture_id;
    _layer      = layer;

    _width  = 50;
    _height = 50;
    _scale  = 1.f;

    _flip = SDL_RendererFlip::SDL_FLIP_NONE;
}

Game_Object::~Game_Object()
{
}

const std::string& Game_Object::get_id() const
{
    return _id;
}

const int& Game_Object::get_width() const
{
    return _width;
}

const int& Game_Object::get_height() const
{
    return _height;
}

const float& Game_Object::get_scale() const
{
    return _scale;
}

const Vector_2D& Game_Object::get_translation() const
{
    return _translation;
}

const Circle_2D* Game_Object::get_collider() const
{
    return _circle_collider;
}

void Game_Object::set_scale(const float& scalar)
{
    _scale = scalar;
}

void Game_Object::simulate_physics(const Uint32& milliseconds_to_simulate, Assets*, Scene* scene)
{
    Vector_2D velocity = _velocity;
    velocity.set_scale((float)milliseconds_to_simulate);

    Vector_2D prev_translation = _translation;
    _translation += velocity;

    if (_is_affected_by_gravity)
    {
        if (_translation.get_y() + _height < 490.f)
        {
            Vector_2D gravity = Vector_2D(0.f, 2.f);
            _translation += gravity;
        }
    }

    // Collision
    for (Game_Object* game_object : scene->get_game_objects())
    {
        if (game_object->get_id() == _id)
        {
            continue;
        }

        // If current object has a circle collider
        if (_circle_collider != nullptr && _rect_collider == nullptr)
        {
            Circle_2D collider = Circle_2D(_circle_collider->get_radius(), _circle_collider->get_translation() + _translation);

            // If other object has a circle collider
            if (game_object->_circle_collider != nullptr && game_object->_rect_collider == nullptr)
            {
                Circle_2D other_collider = Circle_2D(game_object->_circle_collider->get_radius(), game_object->_circle_collider->get_translation() + game_object->_translation);
                float intersection_depth = collider.calculate_intersection_depth(other_collider);

                if (intersection_depth > 0.f)
                {
                    Vector_2D other_collider_to_collider = collider.get_translation() - other_collider.get_translation();
                    other_collider_to_collider.normalise();
                    other_collider_to_collider.set_scale(intersection_depth);
                    _translation += other_collider_to_collider;

                    Vector_2D collider_to_other_collider = other_collider.get_translation() - collider.get_translation();
                    collider_to_other_collider.normalise();
                    collider_to_other_collider.set_scale(intersection_depth);
                    game_object->_translation += collider_to_other_collider;
                }
            }
            // If other object has a rect collider
            else if (game_object->_circle_collider == nullptr && game_object->_rect_collider != nullptr)
            {
                if (_id == "Player")
                {
                    float cx = _circle_collider->get_translation().get_x() + _translation.get_x();
                    float cy = _circle_collider->get_translation().get_y() + _translation.get_y();
                    float test_x = cx;
                    float test_y = cy;
                    float other_x = game_object->_rect_collider->get_rect_x();
                    float other_y = game_object->_rect_collider->get_rect_y();
                    float other_w = game_object->_rect_collider->get_rect_w();
                    float other_h = game_object->_rect_collider->get_rect_h();
                    if (cx < other_x)
                    {
                        test_x = other_x;
                    }
                    else if (cx > other_x + other_w)
                    {
                        test_x = other_x + other_w;
                    }
                    if (cy < other_y)
                    {
                        test_y = other_y;
                    }
                    else if (cy > other_y + other_h)
                    {
                        test_y = other_y + other_h;
                    }
                        

                    float dist_x = cx - test_x;
                    float dist_y = cy - test_y;
                    float distance = sqrt((dist_x * dist_x) + (dist_y * dist_y));

                    // If the distance is less than the radius
                    if (distance <= _circle_collider->get_radius())
                    {
                        _translation = prev_translation;
                    }
                }
            }  
        }
        // If current object has a rect collider
        else if (_circle_collider == nullptr && _rect_collider != nullptr)
        {

        }

        /*Circle_2D collider          = Circle_2D(_collider.get_radius(), _collider.get_translation() + _translation);
        Circle_2D other_collider    = Circle_2D(game_object->_collider.get_radius(), game_object->_collider.get_translation() + game_object->_translation);
        float intersection_depth    = collider.calculate_intersection_depth(other_collider);
        
        if (intersection_depth > 0.f)
        {
            Vector_2D other_collider_to_collider = collider.get_translation() - other_collider.get_translation();
            other_collider_to_collider.normalise();
            other_collider_to_collider.set_scale(intersection_depth);
            _translation += other_collider_to_collider;

            Vector_2D collider_to_other_collider = other_collider.get_translation() - collider.get_translation();
            collider_to_other_collider.normalise();
            collider_to_other_collider.set_scale(intersection_depth);
            game_object->_translation += collider_to_other_collider;
        }*/
    }

}

void Game_Object::render(const Uint32&, Assets* assets, SDL_Renderer* renderer, Scene* scene)
{
    /*SDL_Rect destination;
    destination.x = (int)_translation.get_x() - (int)scene->get_camera()->get_camera_translation().get_x();
    destination.y = (int)_translation.get_y() - (int)scene->get_camera()->get_camera_translation().get_y();
    destination.w = _width;
    destination.h = _height;*/

    if (scene->get_camera() == nullptr)
    {
        std::cout << "Failed to load a camera" << std::endl;
        exit(1);
    }

    SDL_Rect destination;
    /*int camera_y = (int)scene->get_camera()->get_camera_translation().get_y();
    int y = (int)_translation.get_y();
    int gap_y = (int)abs(camera_y - y);
    int camera_height = scene->get_camera()->get_height();

    if (_id == "Player")
    {
        if (gap_y < (camera_height / 2.f))
        {
            destination.y = (int)(camera_height / 2.f) + (int)(gap_y / 2.f);
        }
        else
        {
            destination.y = (int)_translation.get_y() - (int)scene->get_camera()->get_camera_translation().get_y();
            scene->get_camera()->set_camera_y((float)(y - scene->get_camera()->get_height() / 2.f));
        }
    }
    else
    {
        if (gap_y < scene->get_camera()->get_height())
        {
            destination.y = y - (int)scene->get_camera()->get_camera_translation().get_y();
        }
    }*/
    destination.x = (int)_translation.get_x();
    destination.y = (int)_translation.get_y();
    destination.w = _width;
    destination.h = _height;

    const float PI = 3.14159265f;
    if (_velocity.calculate_magnitude() > 0)
    {
        float angle = abs(_velocity.calculate_angle());
        if (angle < (PI / 2.f))
        {
            _flip = SDL_RendererFlip::SDL_FLIP_NONE;
        }
        else if (angle > (PI / 2.f))
        {
            _flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
        }
    }

    Texture* texture = (Texture*)assets->get_asset(_texture_id);
    texture->render(renderer, nullptr, &destination, _flip);

    // Render Objects ID
    if (Configuration::get_instance()->_should_display_ids)
    {
        SDL_Color text_color;
        text_color.r = 50;
        text_color.g = 50;
        text_color.b = 50;
        text_color.a = 0;

        Text id(renderer, _id.c_str(), text_color, "ID.Text");
        id.render(renderer, Vector_2D((float)destination.x, (float)destination.y));//_translation + Vector_2D((float)_width / 2, (float)_height));
    }

    // Render Objects position
    if (Configuration::get_instance()->_should_display_positions)
    {
        SDL_Color text_color;
        text_color.r = 0;
        text_color.g = 50;
        text_color.b = 50;
        text_color.a = 0;

        std::string position_text = "(" + std::to_string(destination.x) + ", " + std::to_string(destination.y) + ")";
        Text position(renderer, position_text.c_str(), text_color, "Position.Text");

        position.render(renderer, Vector_2D((float)destination.x, (float)(destination.y + _height)));//_translation + Vector_2D((float)_width / 2, (float)_height));
    }

    // Render 2D Circle collider
    if (_circle_collider != nullptr && _rect_collider == nullptr)
    {
        if (Configuration::get_instance()->_should_display_colliders && _circle_collider->get_radius() > 0.f)
        {
            Texture* collider_texture = (Texture*)assets->get_asset("Texture.Collider.Circle_2D");

            SDL_Rect collider_destination;
            collider_destination.x = destination.x + (int)(_circle_collider->get_translation().get_x() - _circle_collider->get_radius());//(int)(_translation.get_x() + _collider.get_translation().get_x() - _collider.get_radius());
            collider_destination.y = destination.y + (int)(_circle_collider->get_translation().get_y() - _circle_collider->get_radius());//(int)(_translation.get_y() + _collider.get_translation().get_y() - _collider.get_radius());
            collider_destination.w = (int)(_circle_collider->get_radius() * 2.f);
            collider_destination.h = (int)(_circle_collider->get_radius() * 2.f);

            collider_texture->render(renderer, nullptr, &collider_destination, SDL_RendererFlip::SDL_FLIP_NONE);
        }
    }
    else if (_circle_collider == nullptr && _rect_collider != nullptr)
    {

    }
    
}
