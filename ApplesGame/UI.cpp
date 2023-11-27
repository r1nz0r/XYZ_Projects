#include "UI.h"
#include "Constants.h"
#include <cassert>

namespace ApplesGame
{
    void InitializeLabel(Label& label)
    {
        assert(label.textFont.loadFromFile(RESOURCES_PATH + FONT_NAME));

        label.text.setFont(label.textFont);
        label.text.setCharacterSize(label.textSize);
        label.text.setString(label.message);
        label.text.setPosition(label.position.x, label.position.y);
        label.text.setFillColor(label.color);
    }
}
