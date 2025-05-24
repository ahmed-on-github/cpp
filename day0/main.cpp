#include <iostream>

class Complex{
    float real, imag;

    public:
    /*Constructor functions*/
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(float r){
        real = imag = r;
    }
    Complex(float r, float i){
        real = r;
        imag = i;
    }
    /*Destructor*/
    ~Complex(){
        std::cout << "Class \"Complex\" Destructor called" << std::endl;
    }
    /*Setter Methods*/
    void setReal(float r){
        real = r;
    }
    void setImag(float i){
        imag = i;
    }
    /*Getter Methods*/
    float getReal(){
        return real;
    }
    float getImag(){
        return this->imag;
    }
    Complex* getComplex(){
        return this;
    }
    void printComplex(){
        std::cout << "Real: " << real << ", Imaginary: " << imag << std::endl;
    }
    /*Operations*/
    void add(Complex *a, Complex *b );
    Complex sub(Complex *a, Complex *b);
    Complex mul(Complex *a, Complex *b);
    Complex div(Complex *a, Complex *b);
};
/*Operations*/
    void Complex::add(Complex *a, Complex *b ){
        if(a && b){
            this->real = a->real + b->real;
            this->imag = a->imag + b->imag;
        }
    }
    Complex Complex::sub(Complex *a, Complex *b){
        Complex c;
        c.real = a->real - b->real;
        c.imag = a->imag - b->imag;
        return c;
    }
    Complex Complex::mul(Complex *a, Complex *b){
        Complex c;
        c.real = a->real * b->real - a->imag * b->imag;
        c.imag = a->real * b->imag + a->imag * b->real;
        return c;
    }
    Complex Complex::div(Complex *a, Complex *b){
        Complex c;
        float denom = b->real * b->real + b->imag * b->imag;
        c.real = (a->real * b->real + a->imag * b->imag) / denom;
        c.imag = (a->imag * b->real - a->real * b->imag) / denom;
        return c;
    }


            
int main(){

    Complex a(3.2, 4) , b , c(4);
    std::cout << "Address of Complex a: " << a.getComplex() << std::endl;
    std::cout << "Address of Complex b: " << b.getComplex() << std::endl;
    std::cout << "Address of Complex c: " << c.getComplex() << std::endl;

    a.printComplex();

    c.setImag(-1);
    c.printComplex();

    b.add(&a, &c);
    b.printComplex();

    a = b.sub(&a, &c); /*Distructor of a is called */
    a.printComplex();
    std::cout << "Address of Complex a: " << a.getComplex() << std::endl;
    std::cout << "Address of Complex b: " << b.getComplex() << std::endl;
    std::cout << "Address of Complex c: " << c.getComplex() << std::endl;
    
    c.add(&a, &c); 
    c.printComplex();

    std::cout << "Address of Complex a: " << a.getComplex() << std::endl;
    std::cout << "Address of Complex b: " << b.getComplex() << std::endl;
    std::cout << "Address of Complex c: " << c.getComplex() << std::endl;

    return 0;
}
