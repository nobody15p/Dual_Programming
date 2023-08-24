#include <iostream>
#include <math.h>
#include <fstream>
#include "Duplex.h++"

ofstream fp;

class start_and_step {
public:
    double step, th1, s1, th1dot, s1dot;

    void get_start_and_step(void);

    void default_start_and_step(void);
};

class linkage {
public:
    duplex alpha[5], theta[5];

    void get_links(void);

    void default_links(void);

    void displacements(double th1, double s1);

    void display_displacements(void);
};

void linkage::get_links(void) {
    int n;
    for (n = 1; n <= 4; n++) {
        cout << "\nTwist and length of link " << n << " (2 items) ? ";
        cin >> alpha[n];
        alpha[n] = deg2rad(alpha[n]);
    }
}

void linkage::default_links(void) {
    alpha[1] = deg2rad(duplex(90., 0.));
    alpha[2] = deg2rad(duplex(90., 0.));
    alpha[3] = deg2rad(duplex(90., 0.));
    alpha[4] = deg2rad(duplex(160., 0.));
}

void start_and_step::get_start_and_step(void) {
    cout << "\nInput translation? ";
    cin >> s1;
    cout << "\nStep of size of theta1? ";
    cin >> step;
    th1 = -step;
}

void start_and_step::default_start_and_step(void) {
    s1 = 0.;
    step = 10.;
    th1 = -step;
}

void linkage::display_displacements(void) {
    cout.precision(7);
    cout << "theta = " << rad2deg(theta[1]) << " "
         << rad2deg(theta[2]) << " " << rad2deg(theta[3]) << " " << rad2deg(theta[4]) << "\n";
}

void linkage::displacements(double th1, double s1) {
    duplex D, E, F, t, st2, ct2, st3, ct3;
    theta[1] = deg2rad(duplex(th1, s1));
    // Calculation of output dual angle theta[4]
    D = sin(alpha[1]) * sin(alpha[3]) * sin(theta[1]);
    E = -sin(alpha[3]) * (cos(alpha[1]) * sin(alpha[4])
                          + sin(alpha[1]) * cos(alpha[4]) * cos(theta[1]));
    F = cos(alpha[3]) * (cos(alpha[1]) * cos(alpha[4])
                         - sin(alpha[1]) * sin(alpha[4]) * cos(theta[1])
                         - cos(alpha[2]));
    t = (-D - sqrt(D * D + E * E - F * F)) / (F - E);
    theta[4] = 2. * atan(t);

    // Calculation of intermediate dual angle theta[2]
    st2 = ((cos(alpha[3]) * sin(alpha[4])
            + sin(alpha[3]) * cos(alpha[4]) * cos(theta[4]))
           * sin(theta[1])
           + sin(alpha[3]) * cos(theta[1]) * sin(theta[4]))
          / sin(alpha[2]);

    ct2 = (cos(alpha[1]) * cos(alpha[2])
           - cos(alpha[3]) * cos(alpha[4]) + sin(alpha[3]) * sin(alpha[4]) * cos(theta[4]))
          / (sin(alpha[1]) * sin(alpha[2]));

    theta[2] = atan2(st2, ct2);
    // Calculation of intermediate dual angle theta[3]
    st3 = (cos(alpha[1]) * sin(alpha[4]) * sin(theta[1])
           + sin(alpha[1]) *
             (sin(theta[1]) * cos(theta[4]) + cos(alpha[4]) * cos(theta[1]) * sin(theta[4])))
          / sin(alpha[2]);

    ct3 = (-cos(alpha[1]) * cos(alpha[4]) + cos(alpha[2]) * cos(alpha[3])
           + sin(alpha[1]) * sin(alpha[4]) * cos(theta[1]))
          / (sin(alpha[2]) * sin(alpha[3]));

    theta[3] = atan2(st3, ct3);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n;
    linkage mechanism;
    start_and_step index;
    char choice;
    cout << "RCCC\n(when multiple items requested, separate by spaces) \n \nUse default mechanism (y/n)? ";
    cin >> choice;
    if (choice == 'y') {
        mechanism.default_links();
        index.default_start_and_step();
    } else {
        mechanism.get_links();
        index.get_start_and_step();
    }

    while (index.th1 <= 360) {
        mechanism.displacements(index.th1, index.s1);
        mechanism.display_displacements();
        index.th1 += index.step;
    }

    return 0;
}
