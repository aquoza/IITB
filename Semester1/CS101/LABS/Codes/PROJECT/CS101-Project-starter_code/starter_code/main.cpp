#include <simplecpp>
#include <sstream>
#include "shooter.h"
#include "bubble.h"

/* Simulation Vars */
const double STEP_TIME = 0.02;

/* Game Vars */
const int PLAY_Y_HEIGHT = 450;
const int LEFT_MARGIN = 70;
const int TOP_MARGIN = 20;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);


void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME);
    }
}

vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, 0, COLOR(255, 0,0)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, 0, COLOR(0,0,255)));
    return bubbles;
}


int main()
{
    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));
/*
    int health = 3;
    ostringstream str1;
    str1 << health;
    string healt = str1.str();
*/
    string health = "HHH";
    Text health_str(250, 250, health);

    string msg_cmd("Cmd: _");
    Text charPressed(LEFT_MARGIN, BOTTOM_MARGIN, msg_cmd);

    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;

    XEvent event;

                                       //abs(bubbles[i].get_center_x() - shooter.get_body_center_x()) < bubbles[i].get_radius()
    // Main game loop
    while (true)
    {
        for (int i = 0;i < bubbles.size() &&bubbles.size()>0; i++ ){
            if(((bubbles[i].get_vx() < 0) && (bubbles[i].get_center_x() == shooter.get_body_center_x()+ 9) && (bubbles[i].get_center_y() > PLAY_Y_HEIGHT - shooter.get_body_height()- 2*shooter.get_head_radius()))||
               ((bubbles[i].get_vx() > 0) && (bubbles[i].get_center_x() == shooter.get_body_center_x()- 9) && (bubbles[i].get_center_y() > PLAY_Y_HEIGHT - shooter.get_body_height()- 2*shooter.get_head_radius()))||
               ((bubbles[i].get_vy() > 0) && (bubbles[i].get_center_y() == PLAY_Y_HEIGHT - shooter.get_body_height() - 2*shooter.get_head_radius()) && (bubbles[i].get_center_x() < shooter.get_body_center_x()+ 9 )&&
               (bubbles[i].get_center_x() > shooter.get_body_center_x()- 9))
                ){
                health.pop_back();
                health_str.setMessage(health);
            }
        }


        //collision of bubble and bullet
        for (int i = 0;i < bubbles.size(); i++ ){
            for (int j = 0;j < bullets.size() && bullets.size() > 0; j++ ){
                if ( (bullets[j].get_center_x()< bubbles[i].get_center_x()+ 10)&& (bullets[j].get_center_x()> bubbles[i].get_center_x()- 10)&&
                     (bullets[j].get_center_y()< bubbles[i].get_center_y()+ 10)&& (bullets[j].get_center_y()> bubbles[i].get_center_y()- 10)
                    ){
                    bullets.erase(bullets.begin() + j);
                    bubbles.erase(bubbles.begin() + i);
                }
            }
        }

        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
        }

        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);

        wait(STEP_TIME);
    }
}
