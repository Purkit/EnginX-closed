#ifndef LAYER_STACK_HPP
#define LAYER_STACK_HPP

#include <vector>
#include <algorithm>
#include <enginx/layers/layers.hpp>

namespace enginx
{
    class LayerStack
    {
        public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
            void PopLayer(Layer* layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        
        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerIndex;

    };
}

#endif // LAYER_STACK_HPP