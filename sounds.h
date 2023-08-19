#pragma once
#ifndef SOUNDS_H
#define SOUNDS_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class sounds
{
protected:
    sf::SoundBuffer start_sound_buffer;
    sf::Sound start_sound;

    sf::SoundBuffer bullet_sound_buffer;
    sf::Sound bullet_sound;

    sf::SoundBuffer traffic_sound_buffer;
    sf::Sound traffic_sound;

    sf::SoundBuffer crash_sound_buffer;
    sf::Sound crash_sound;

    sf::SoundBuffer petrol_sound_buffer;
    sf::Sound petrol_sound;

    sf::SoundBuffer beep_sound_buffer;
    sf::Sound beep_sound;

public:
    sounds();
    
    void play_start_sound();
    
    void play_bullet_sound();

    void play_traffic_sound();

    void play_crash_sound();

    void play_petrol_sound();

    void play_beep_sound();

    void stop_beep_sound();

    ~sounds(){}

};
#endif // SOUNDS_H

