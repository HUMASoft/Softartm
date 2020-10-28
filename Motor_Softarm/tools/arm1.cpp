#include "Cia402device.h"
#include "CiA301CommPort.h"
#include "SocketCanPort.h"
#include <iostream>
#include <stdio.h>


int main ()
{
    //--Can port communications--
    SocketCanPort pm1("can1");
    CiA402SetupData sd1(2048,157,0.001, 1.25, 20 );
    CiA402Device m1 (31, &pm1, &sd1);
    m1.SetupPositionMode(1,1);

    SocketCanPort pm2("can1");
    CiA402SetupData sd2(2048,157,0.001, 1.25, 20 );
    CiA402Device m2 (32, &pm2, &sd2);    //--Can port communications--
    m2.SetupPositionMode(1,1);

    SocketCanPort pm3("can1");
    CiA402SetupData sd3(2048,157,0.001, 1.25, 20 );
    CiA402Device m3 (33, &pm3, &sd3);
    m3.SetupPositionMode(1,1);
//    m3.Setup_Velocity_Mode();


    // motors must be turned ON

    double pos;
    double vel;

    m1.Reset();
    sleep(1);
    m1.SwitchOn();

    m2.Reset();
    sleep(1);
    m2.SwitchOn();

    // position  [rads]
    cout << m1.GetPosition() << endl;
    cout << m2.GetPosition() << endl;
    cout << m3.GetPosition() << endl;

    m1.SetPosition(-2);
//    m3.SetVelocity(1);

    sleep(4);
    cout << m1.GetPosition() << endl;

//    m1.SetVelocity(0);




}
