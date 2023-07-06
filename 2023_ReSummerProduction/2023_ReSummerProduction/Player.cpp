#include "Player.h"

Player::Player()
{
    x = 0;
    y = 0;
    stageY = 0;
    JampY = 0;
    JampST = 5;
    Stoping = 0;
    SpeedL = 0;
    SpeedR = 0;
    OldKey = 0;

    isJamp = false;
    isGround = false;
}

void Player::Update()
{
    Jamp();
	PMove();
}

void Player::PDraw()
{
	DrawCircle(100 + x, 100 + y, 10, 0xffffff, TRUE);
    DrawGraph(85 + x, 80 + y, Image::MarioImg[0], TRUE);
}

void Player::PMove()
{
    /**********ç∂ï˚å¸*************/
    if ((PadInput::flgX != 0 && PadInput::inputX < -MARGIN))
    {
        if (PadInput::OnPressed(XINPUT_BUTTON_A))
        {
            if (SpeedL < MaxSpeed)
            {
                SpeedL += (MaxSpeed / runTime) * 10;
            }
            else
            {
                SpeedL = MaxSpeed;
            }
        }
        else
        {
            if (SpeedL > MinSpeed)
            {
                SpeedL = MinSpeed;
            }
            else {
                if (SpeedL < MinSpeed)
                {
                    SpeedL += (MinSpeed / walkTime) * 2;
                }
            }
        }
    }
    else
    {
        if (SpeedL > 0)
        {
            SpeedL -= Inertia;
        }

        //if (SpeedL > MinSpeed + 0.1f)
        //{
        //    if (SpeedL > 0)
        //    {
        //        SpeedL -= Inertia;
        //    }
        //}
        //else
        //{
        //    if (SpeedL > 0)
        //    {
        //        SpeedL -= Inertia;
        //    }
        //}


        if (OldKey == 1 && SpeedL > 0)
        {
            x -= SpeedL;
        }
    }

    /**********âEï˚å¸*************/
    if ((PadInput::flgX != 0 && PadInput::inputX > MARGIN))
    {
        if (PadInput::OnPressed(XINPUT_BUTTON_A))
        {
            if (SpeedR < MaxSpeed)
            {
                SpeedR += (MaxSpeed / runTime) * 10;
            }
            else
            {
                SpeedR = MaxSpeed;
            }
        }
        else
        {
            if (SpeedR > MinSpeed)
            {
                SpeedR = MinSpeed;
            }
            else {
                if (SpeedR < MinSpeed)
                {
                    SpeedR += (MinSpeed / walkTime) * 2;
                }
            }
        }
    }
    else 
    {
        if (SpeedR > 0)
        {
            SpeedR -= Inertia;
        }

        //if (SpeedR > MinSpeed + 0.1f)
        //{
        //    if (SpeedR > 0)
        //    {
        //        SpeedR -= Inertia;
        //    }
        //}
        //else
        //{
        //    if (SpeedR > 0)
        //    {
        //        SpeedR -= Inertia;
        //    }
        //}

        if (OldKey == 2 && SpeedR > 0)
        {
            x += SpeedR;
        }
    }



    //ç∂ï˚å¸
    if (PadInput::flgX != 0 && PadInput::inputX < -MARGIN && SpeedR < MinSpeed) {
        x -= SpeedL;
        OldKey = 1;
    }
    //âEï˚å¸
    if (PadInput::flgX != 0 && PadInput::inputX > MARGIN && SpeedL < MinSpeed) {
        x += SpeedR;
        OldKey = 2;
    }
}

void Player::getStage(int y)
{
    stageY = y;
}

void Player::Jamp()
{
    if (PadInput::OnClick(XINPUT_BUTTON_B) && !isJamp)
    {
        isJamp = true;
    }

    if (isJamp && isGround)
    {
        if (JampY < 50)
        {
            if (JampY > 35)
            {
                JampY += 2;
            }
            else
            {
                JampY += JampST;
            }
            y -= JampST;
        }
        else if (Stoping < 10)
        {
            Stoping++;
        }
        else
        {
            JampY = 0;
            Stoping = 0;
            isGround = false;
        }
    }


    if (!isGround)
    {
        if (y + 100 + 10 < stageY)
        {
            y += 2;
        }
        else
        {
            isJamp = false;
            isGround = true;
        }
    }
}