#include "sounds.h"

sounds::sounds()
{
    start_sound_buffer.loadFromFile("sound/start.wav");

    bullet_sound_buffer.loadFromFile("sound/bullet.wav");

    traffic_sound_buffer.loadFromFile("sound/traffic.wav");

    crash_sound_buffer.loadFromFile("sound/crash.wav");

    petrol_sound_buffer.loadFromFile("sound/gas.wav");

    beep_sound_buffer.loadFromFile("sound/beep.wav");

}

void sounds::play_start_sound()
{
    start_sound.setBuffer(start_sound_buffer);
    start_sound.play();
}

void sounds::play_bullet_sound()
{
    bullet_sound.setBuffer(bullet_sound_buffer);

    bullet_sound.play();
}

void sounds::play_traffic_sound()
{
    traffic_sound.setBuffer(traffic_sound_buffer);

    traffic_sound.play();
}

void sounds::play_crash_sound()
{
    crash_sound.setBuffer(crash_sound_buffer);

    crash_sound.play();
}

void sounds::play_petrol_sound()
{
    petrol_sound.setBuffer(petrol_sound_buffer);
    petrol_sound.play();
}

void sounds::play_beep_sound()
{
    beep_sound.setBuffer(beep_sound_buffer);
    beep_sound.play();
}
void sounds::stop_beep_sound()
{
    beep_sound.stop();
}