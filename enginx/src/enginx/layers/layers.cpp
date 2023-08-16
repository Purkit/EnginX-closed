#include <enginx/layers/layers.hpp>

namespace enginx
{
    Layer::Layer(const u8 LayerID)
        : m_LayerID(LayerID)
    {}

    Layer::~Layer() {}
}