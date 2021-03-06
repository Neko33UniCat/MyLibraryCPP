//
//  Vector2.hpp
//
//  Created by Neko on 2019/09/07.
//

#ifndef Vector2_hpp
#define Vector2_hpp
#include <string>
#include <cmath>
using namespace std;

namespace Vector{
    class Vector2{
    public:
        double x;
        double y;
        Vector2(double a = 0.0,double b = 0.0) :x(a),y(b) {}

        Vector2 operator + (const Vector2 &A);
        Vector2 operator - (const Vector2 &A);
        Vector2 operator * (const int &A);
        bool operator == (const Vector2 &A);
        bool operator != (const Vector2 &A);
        bool operator &= (const Vector2 &A);
        bool operator < (const Vector2 &A);
        bool operator > (const Vector2 &A);
        bool operator <= (const Vector2 &A);
        bool operator >= (const Vector2 &A);
        template<typename T> Vector2 operator * (const T &A);
        template<typename T> Vector2 operator / (const T &A);  
        double size();
        string ToString();
        bool IsVertical(Vector2 vector);
        bool IsParallel(Vector2 vector);
        Vector2 Unit();
        Vector2 OrthographicProjection(Vector2 A);
        double Angle(Vector2 A);
    private :
        double InnerMultiplication(Vector2 a);
    };

    Vector2 Vector2::operator+(const Vector2 &A){
        Vector2 C;
        C.x=x+A.x;
        C.y=y+A.y;
        return C;
    }

    Vector2 Vector2::operator - (const Vector2 &A){
        Vector2 C;
        C.x=x-A.x;
        C.y=y-A.y;
        return C;
    }
    bool Vector2::operator==(const Vector2 &A){
        if(x==A.x && y==A.y){
            return true;
        }else{
            return false;
        }
    }
    bool Vector2::operator!=(const Vector2 &A){
        if(x==A.x && y==A.y){
            return false;
        }else{
            return true;
        }
    }
    bool Vector2::operator&=(const Vector2 &A){
        double s = sqrt(A.x*A.x + A.y*A.y);
        if (size()==s){
            return true;
        }else{
            return false;
        }
        
    }
    bool Vector2::operator<(const Vector2 &A){
        double s = sqrt(A.x*A.x + A.y*A.y);
        if (size()<s){
            return true;
        }else{
            return false;
        }
        
    }
    bool Vector2::operator>(const Vector2 &A){
        double s = sqrt(A.x*A.x + A.y*A.y);
        if (size()>s){
            return true;
        }else{
            return false;
        }
        
    }
    bool Vector2::operator<=(const Vector2 &A){
        double s = sqrt(A.x*A.x + A.y*A.y);
        if (size()<=s){
            return true;
        }else{
            return false;
        }
        
    }
    bool Vector2::operator>=(const Vector2 &A){
        double s = sqrt(A.x*A.x + A.y*A.y);
        if (size()>=s){
            return true;
        }else{
            return false;
        }
        
    }
    template<typename T> Vector2 Vector2::operator*(const T &A){
        Vector2 C;
        C.x=A*x;
        C.y=A*y;
        return  C;
    }
    template<typename T> Vector2 Vector2::operator/(const T &A){
        Vector2 C;
        C.x=x/A;
        C.y=y/A;
        return C;
    }

    bool Vector2::IsVertical(Vector2 vector){
        if(x*vector.x+y*vector.y==0){
            return true;
        }else{
            return false;
        }
    }
    bool Vector2::IsParallel(Vector2 vector){
        if(y*vector.x-vector.y*x==0){
            return true;
        }else{
            return false;
        }
    }
    double Vector2::size(){
        return sqrt(x*x + y*y);
    }
    Vector2 Vector2::Unit(){
        Vector2 v(x,y);
        return v/size();
    }
    Vector2 Vector2::OrthographicProjection(Vector2 A){
        Vector2 X(x,y);
        double k = X.InnerMultiplication(A);
        double l = A.InnerMultiplication(A);
        double m = k/l;
        Vector2 R(m*A.x,m*A.y);
        return R;
    }
    double Vector2::Angle(Vector2 B){
        Vector2 A(x,y);
        double Pr = A.x*B.x+A.y*B.y;
        double cos = Pr/(A.size()*B.size());
        return acos(cos);
    }
    string Vector2::ToString(){
        string S;
        S="("+to_string(x)+", "+to_string(y)+")";
        return  S;
    }
    double Vector2::InnerMultiplication(Vector2 a){
        return x*a.x+y*a.y;
    }
    Vector2 Up = Vector2(0.0,1.0);
    Vector2 Down = Vector2(0.0,-1.0);
    Vector2 Right = Vector2(1.0,0.0);
    Vector2 Left = Vector2(-1.0,0.0);
    Vector2 Zero = Vector2(0.0,0.0);
    Vector2 One = Vector2(1.0,1.0);
}

#endif /* Vector2_hpp */
