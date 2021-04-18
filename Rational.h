//
// Created by A. Harrison Owen on 4/17/2021.
//

#ifndef CS202HW5_READWRITE_MYRATIONAL_H
#define CS202HW5_READWRITE_MYRATIONAL_H

#include <ostream>

template <class R>
class Rational{
    template<class U>
    friend Rational <R> operator+(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend Rational <R> operator-(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend Rational <R> operator*(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend Rational <R> operator/(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator<(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator<=(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator>(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator>=(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator==(Rational<R> lhs, Rational<R> rhs);
    template<class U>
    friend bool operator!=(Rational<R> lhs, Rational<R> rhs);

public:

    R _num, _den;

    Rational();
    Rational(R num);
    Rational(R num, R den);
    Rational<R> &operator+=(const Rational<R> &rhs);
    Rational<R> &operator/=(const Rational<R> &rhs);
    Rational<R> &operator*=(const Rational<R> &rhs);
    Rational<R> &operator-=(const Rational<R> &rhs);
    Rational<R> &operator-();
};

template <class R>
Rational <R>::Rational() : _num(0), _den(0){}

template <class R>
Rational <R>::Rational(R num) : _num(num), _den(1){}

template <class R>
Rational <R>::Rational(R num, R den) : _num(num), _den(den){}

template <class R>
Rational <R> operator+(Rational <R> lhs, Rational <R> rhs){
    return {lhs._num * rhs._den + lhs._den * rhs._num, lhs._den * rhs._den};
}

template <class R>
Rational <R> operator-(Rational <R> lhs, Rational <R> rhs){
    return {lhs._num * rhs._den - lhs._den * rhs._num, lhs._den * rhs._den};
}

template <class R>
Rational <R> operator*(Rational <R> lhs, Rational <R> rhs){
    return {lhs._num * rhs._num, lhs._den * rhs._den};
}

template <class R>
Rational <R> operator*(Rational <R> lhs, int rhs){
    return {lhs._num * rhs, lhs._den};
}

template <class R>
Rational <R> operator/(Rational <R> lhs, Rational <R> rhs){
    return {lhs._num * rhs._den, lhs._den * rhs._num};
}

template <class R>
bool operator<(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den < lhs._den * rhs._num);
}

template <class R>
bool operator>(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den > lhs._den * rhs._num);
}

template <class R>
bool operator<=(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den <= lhs._den * rhs._num);
}

template <class R>
bool operator>=(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den >= lhs._den * rhs._num);
}

template <class R>
bool operator!=(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den != lhs._den * rhs._num);
}

template <class R>
bool operator==(Rational <R> lhs, Rational <R> rhs){
    return (lhs._num * rhs._den == lhs._den * rhs._num);
}

template <class R>
Rational <R> &Rational <R>::operator+=(const Rational <R> &rhs){
    return *this = *this + rhs;
}

template <class R>
Rational <R> &Rational <R>::operator-=(const Rational <R> &rhs){
    return {*this = *this - rhs};
}

template <class R>
Rational <R> &Rational <R>::operator*=(const Rational <R> &rhs){
    return {*this = *this * rhs};
}

template <class R>
Rational <R> &Rational <R>::operator/=(const Rational <R> &rhs){
    return {*this = *this / rhs};
}

template <class R>
Rational <R> &Rational <R>::operator-(){
    return {*this = *this * -1};
}

template <class R>
std::ostream &operator<<(std::ostream &os, const Rational<R> &r){
    if(r._num != 0){
        return os << r._num << "/" << r._den;
    }
    else{
        return os << "0";
    }
}
#endif //CS202HW5_READWRITE_MYRATIONAL_H
