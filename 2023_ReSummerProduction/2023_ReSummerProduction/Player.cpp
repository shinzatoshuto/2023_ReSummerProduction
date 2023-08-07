#include "Player.h"
#include <math.h>

Player::Player()
{
    prct.left = 100;
    prct.top = 400;
    prct.right = 100 + Player_Width;
    prct.bottom = 400 + Player_Height;

    //SetValue(prct, Player_Width, Player_Height);

    x = 300;
    y = 50;
    stageY = 0;
    JampY = 0;
    Stoping = 0;
    SpeedL = 0;
    SpeedR = 0;
    OldKey = 0;
    JampPower = 0;
    StrongPower = 0;
    JampStop = 0;
    Sub = -16;
    oldJamp = 0;
    GravityPower = 0;
    Change = 1;
    Switch = 0;
    WalkWait = 0;

    isJamp = false;
    isGround = false;
    isHit = false;
    isPresse = true;
}

void Player::Update()
{
    Jamp();
	PMove();

    if (x < 0)  //画面は時から出ないようにする
    {
        x = 0;
    }

    prct.left = x;
    prct.right = x + Player_Width;

    prct.top = y;
    prct.bottom = y + Player_Height;
    clsDx();
    printfDx("JampY %ld\n", JampY);
    printfDx("by %ld\n", prct.bottom);
    printfDx("SpeedL %ld\n", SpeedL);
    printfDx("SpeedR %ld\n", SpeedR);
}

void Player::PDraw()
{
    DrawBox(prct.left, prct.top, prct.right, prct.bottom, 0xffffff, TRUE);

    if (SpeedL <= 0 && SpeedR <= 0 && !isJamp)  //停止時
    {
        if (OldKey == 1) //左
        {
            DrawTurnGraph(prct.left - 6, prct.top, Image::MarioImg[0], TRUE);
        }
        else //右
        {
            DrawGraph(prct.left - 6, prct.top, Image::MarioImg[0], TRUE);
        }
    }
    else if(!isJamp)  //移動時
    {
        if (SpeedL > 0)  //左
        {
            if (OldKey == 2)  Change = 1;

            if (SpeedL > MinSpeed)  //ダッシュ
            {
                DrawTurnGraph(prct.left - 6, prct.top, Image::MarioImg[Change], TRUE);
                if (Change > 3) Switch = 1;
                else if (Change < 1) Switch = 0;
                switch (Switch)
                {
                case 0:
                    Change++;
                    break;

                case 1:
                    Change--;
                    break;

                default:
                    break;
                }
            }
            else  //ウォーク
            {
                if (PadInput::inputX > -MARGIN && SpeedL < 1.f) WalkWait = 0;
                DrawTurnGraph(prct.left - 6, prct.top, Image::MarioImg[Change], TRUE);
                if (Change > 2) Switch = 1;
                else if (Change < 1) Switch = 0;
                if (WalkWait++ > 3)
                {
                    WalkWait = 0;
                    switch (Switch)
                    {
                    case 0:
                        Change++;
                        break;

                    case 1:
                        Change--;
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        else  //右
        {
            if (OldKey == 1) {
                Change = 1;
                WalkWait = 0;
            }

            if (SpeedR > MinSpeed)  //ダッシュ
            {
                DrawGraph(prct.left - 6, prct.top, Image::MarioImg[Change], TRUE);
                if (Change > 3) Switch = 1;
                else if (Change < 1) Switch = 0;
                switch (Switch)
                {
                case 0:
                    Change++;
                    break;

                case 1:
                    Change--;
                    break;

                default:
                    break;
                }
            }
            else  //ウォーク
            {
                if (PadInput::inputX < MARGIN && SpeedR < 1.f) WalkWait = 0;
                DrawGraph(prct.left - 6, prct.top, Image::MarioImg[Change], TRUE);
                if (Change > 2) Switch = 1;
                else if (Change < 1) Switch = 0;
                if (WalkWait++ > 3)
                {
                    WalkWait = 0;
                    switch (Switch)
                    {
                    case 0:
                        Change++;
                        break;

                    case 1:
                        Change--;
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
    else  //ジャンプ時
    {
        if (OldKey == 1) //左
        {
            DrawTurnGraph(prct.left - 6, prct.top, Image::MarioImg[5], TRUE);
        }
        else //右
        {
            DrawGraph(prct.left - 6, prct.top, Image::MarioImg[5], TRUE);
        }
    }

    DrawFormatString(0, 0, 0xffffff, "%d", prct.top);
}

void Player::PMove()
{
    /**********左方向*************/
    if ((PadInput::flgX != 0 && PadInput::inputX < -MARGIN))
    {
        if (PadInput::OnPressed(XINPUT_BUTTON_A))
        {
            if (SpeedL < MaxSpeed)
            {
                SpeedL += (MaxSpeed / runTime) * 5;
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
        else
        {
            SpeedL = 0;
        }

        if (OldKey == 1 && SpeedL > 0)
        {
            x -= SpeedL;
        }
    }

    /**********右方向*************/
    if ((PadInput::flgX != 0 && PadInput::inputX > MARGIN))
    {
        if (PadInput::OnPressed(XINPUT_BUTTON_A))
        {
            if (SpeedR < MaxSpeed)
            {
                SpeedR += (MaxSpeed / runTime) * 5;
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
        else
        {
            SpeedR = 0;
        }

        if (OldKey == 2 && SpeedR > 0)
        {
            x += SpeedR;
        }
    }



    //左方向
    if (PadInput::flgX != 0 && PadInput::inputX < -MARGIN && SpeedR < MinSpeed) {
        x -= SpeedL;
        OldKey = 1;
    }
    //右方向
    if (PadInput::flgX != 0 && PadInput::inputX > MARGIN && SpeedL < MinSpeed) {
        x += SpeedR;
        OldKey = 2;
    }
}

void Player::Jamp()
{
    if (PadInput::OnClick(XINPUT_BUTTON_B) && !isJamp)
    {
        isJamp = true;
        isPresse = false;
        isHit = false;
    }
    if (PadInput::OnPressed(XINPUT_BUTTON_B) && !isPresse)
    {

    }
    else 
    {
        isPresse = true;
        JampY = 0;
        Sub = -16;
    }

    if (isJamp && isGround)
    {
        if (!isPresse && !isHit)
        {
            if (abs((long)JampPower) < 1.0f && Sub != -16)
            {
                JampPower += 0.1f;
            }
            else
            {
                JampPower = JampPower + Sub;
            }
            y += JampPower;
            Sub = Gravity;
        }
        else
        {
            isGround = false;
            if (JampPower >= 0) GravityPower = JampPower;
            else GravityPower = 0;
            JampPower = 0;
        }
    }

    if (!isGround)
    {
        if (!isHit)
        {
            GravityPower += Gravity;
            y += GravityPower;
        }
        else
        {
            isJamp = false;
            isGround = true;

            GravityPower = 0;
            prct.top = prct.top;
            prct.bottom = prct.bottom;
        }
    }
}