    #include "sign.h"
    #include <Arduino.h>
    
    unsigned char Sign::letter(char L)
    {
        switch(L)
        {
            case 'T': return 0;
            case 'E': return 1;
            case 'C': return 2;
            case 'H': return 3;
            case 'N': return 4;
            case 'O': return 5;
            case 'P': return 6;
            case 'A': return 7;
            case 'R': return 8;
            case 'K': return 9;
            default: return 10;
        }
    }

    void Sign::set(char letter, rgb_color color)
    {
        uint8_t id = Sign::letter(letter);
        if (id >= LETTER_COUNT)
        {
            printf("Letter not found");
            return;
        }
        Sign::set(id, color);
    }
    
    void Sign::set(uint8_t id, rgb_color color)
    {
        for (uint16_t arrId = _letterStart[id]; arrId < _letterStop[id]; ++arrId)
        {
            _colorValues[arrId] = color;
        }
        Sign::update();
    }

    void Sign::setAll(rgb_color color)
    {
        for (uint16_t arrId = 0; arrId < LED_COUNT_TOTAL; ++arrId)
        {
            _colorValues[arrId] = color;
        }
        Sign::update();
    }

    void Sign::update()
    {
        _ledStrip.write(_colorValues, LED_COUNT_TOTAL);
    }

    Sign::Sign()
    {
        uint8_t currentCount = 0;
        for (uint8_t letterId = 0; letterId < LETTER_COUNT; ++letterId)
        {
            _letterStart[letterId] = currentCount;
            currentCount += _ledCounts[letterId];
            _letterStop[letterId] = currentCount;
        }

    }
