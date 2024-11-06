#include <iostream>
#include <cmath>

class Electric_Field 
{
  private:

     double* E;
  
  public: 
    Electric_Field(double ex = 0.0, double ey = 0.0, double ez = 0.0) 
    {
       E = new double[3]{ex, ey, ez};  
    }
   
    ~Electric_Field() 
    {
       delete[] E;  
    }

    
    double getX() const {return E[0];}
    double getY() const {return E[1];}
    double getZ() const {return E[2];}

    
    void setX(double ex) {E[0] = ex;}
    void setY(double ey) {E[1] = ey;}
    void setZ(double ez) {E[2] = ez;}

   
    double calculateMagnitude() const 
    {
      return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    
    double calculateInnerProduct() const 
    {
      return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

class Magnetic_Field 
{
  private:

     double* B;
  
  public:
    Magnetic_Field(double bx = 0.0, double by = 0.0, double bz = 0.0) 
    {
      B = new double[3] {bx, by, bz}; 
    }

   ~ Magnetic_Field() 
    {
      delete[] B;  
    }

    
      double getX() const {return B[0];}
      double getY() const {return B[1];}
      double getZ() const {return B[2];}

      void setX(double bx) {B[0] = bx;}
      void setY(double by) {B[1] = by;}
      void setZ(double bz) {B[2] = bz;}

 double calculateMagnitude() const 
 {
   return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
 }

    
 void calculateUnitVector() const 
 {
    double magnitude = calculateMagnitude();
       if (magnitude != 0)
       {
         std::cout << "Magnetic Field Unit Vector: ("
                   << B[0] / magnitude << ", "
                   << B[1] / magnitude << ", "
                   << B[2] / magnitude << ")" << std::endl;
        } else {
            std::cout << "Magnetic Field magnitude is zero, cannot compute unit vector." << std::endl;
        }
  }
};



int main() 
{
    Electric_Field E_default;
       std::cout << "Default Electric Field Magnitude: " << E_default.calculateMagnitude() << std::endl;

  
    Electric_Field E_components(1e5, 10.9, 1.7e2);
       std::cout << "Electric Field Magnitude with components: " << E_components.calculateMagnitude() << std::endl;

    
    	E_default.setX(3.0);
    	E_default.setY(4.0);
    	E_default.setZ(12.0);
    	   std::cout << "Updated Electric Field Magnitude: " << E_default.calculateMagnitude() << std::endl;
  
    double innerProduct = E_components.calculateInnerProduct();
       std::cout << "Electric Field Inner Product: " << innerProduct << std::endl;

   
    Magnetic_Field B_default;
       std::cout << "Default Magnetic Field Magnitude: " << B_default.calculateMagnitude() << std::endl;

   
    Magnetic_Field B_components(0.5, 2.5, -1.0);
       std::cout << "Magnetic Field Magnitude with components: " << B_components.calculateMagnitude() << std::endl;

   
    	B_default.setX(1.0);
    	B_default.setY(0.0);
    	B_default.setZ(-3.0);
    	   std::cout << "Updated Magnetic Field Magnitude: " << B_default.calculateMagnitude() << std::endl;

    
    	B_components.calculateUnitVector();

  return 0;
}
