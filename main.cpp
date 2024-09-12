#include <iostream>
#include <cmath>


const double left_border = 1.00; // Left border
const double right_border = 1.75; // Right border
const double eps = 1e-5; // accuracy

void standard_newtons_method (const double & a, const double & b, const double & eps);
void simplified_newtons_method (const double & a, const double & b, const double & eps);


int main(){
    std::cout << "Left border:\t" << left_border << '\n';
    std::cout << "Right border:\t" << right_border << '\n';
    std::cout << "Accuracy:\t" << eps << '\n';
    std::cout << "Function:\t4x-x^4\n";
    standard_newtons_method (left_border, right_border, eps);
    simplified_newtons_method (left_border, right_border, eps);
    return 0;
}


double original_function (const double & x) {
    return 4*x - pow(x,4);
}


double diff (const double & x) {
    return 4 - 4*pow(x,3);
}


double diff2 (const double & x) {
    return -12*pow(x,2);
}


void standard_newtons_method (const double & a, const double & b, const double & eps) {
    std::cout << "Standard Newton's method\n";
    double c = (original_function(a) * diff2(b) > 0) ? c = a : c = b; // initial approximation
    int n = 0;
    do {
        ++n;
        c = c - original_function(c) / diff(c);
        std::cout << n << '\t' << c << '\n';
    } while (std::fabs(original_function(c)) >= eps);
}


void simplified_newtons_method (const double & a, const double & b, const double & eps) {
    std::cout << "Simplified Newton's method\n";
    int n = 0;
    double c = (original_function(a) * diff2(b) > 0) ? c = a : c = b; // initial approximation
    double k = c;
    do {
        ++n;
        c = c - original_function(c) / diff(k);
        std::cout << n << '\t' << c << '\n';
    } while (std::fabs(original_function(c)) >= eps);
}