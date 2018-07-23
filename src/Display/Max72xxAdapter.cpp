#include "Max72xxAdapter.h"

namespace MuzicAnalyser { namespace Display 
{
    Max72xxAdapter::Max72xxAdapter(Max72xxPanel* max72xxPanel)
    {
        this->panel = max72xxPanel;
    }

    void Max72xxAdapter::DrawRectangle(Point p0, Point p1)
    {
        this->panel->drawLine(p0.x, p0.y, p1.x, p1.y, HIGH);
    }

    void Max72xxAdapter::SetBrightness(int8_t value)
    {
        this->panel->setIntensity(value);
    }

    void Max72xxAdapter::FlushBuffer()
    {
        this->panel->write();
    }    
    
    void Max72xxAdapter::Clear()
    {
        this->panel->fillScreen(LOW);
    }

    uint16_t Max72xxAdapter::GetDisplaySize(bool vertical)
    {
        return vertical ? this->panel->height() : this->panel->width();
    }

    Max72xxAdapter::~Max72xxAdapter()
    {

    }
} }