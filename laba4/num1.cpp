#include <iostream>
#include <list>
#include <memory>
#include <algorithm>
 
enum class Type
{
   Ship,
   Car,
   Plane
};
 
class CVehicle
{
public:
   struct Coords
   {
      Coords(int x_, int y_):x(x_), y(y_)
      {
      }
      Coords():Coords(0, 0)
      {
      }
      int x, y;
   };
  
   virtual ~CVehicle()
   {
   }
   
   const Coords& get_coords() const { return current_coords; }
   void set_coords(const Coords& c) { current_coords = c; }
   void set_coords(const int x, const int y) { set_coords(Coords(x, y)); }
   const double get_amount() const { return amount; }
   const size_t get_speed() const { return max_speed; }
   const size_t get_year() const { return year; }
   virtual Type get_type() const = 0;
protected:
   CVehicle(const Coords& coords, const double am, const size_t speed, const size_t y):
   current_coords(coords), amount(am), max_speed(speed), year(y)
   {
   }
   Coords current_coords;
   double amount;
   size_t max_speed;
   size_t year;
};
 
class IPassNumber
{
public:
   IPassNumber(const size_t pass_n):pass_no(pass_n)
   {
   }
   virtual ~IPassNumber()
   {
   }
   const size_t get_pass_no() const { return pass_no; }
private:
   size_t pass_no;
};
 
class CPlane : public CVehicle, public IPassNumber
{
public:
   CPlane
   (
      const Coords& coords, const double amount, const size_t speed, const size_t year,
      const size_t h, const size_t pass_no
   ):CVehicle(coords, amount, speed, year), IPassNumber(pass_no), height(h)
   {
   }
   CPlane
   (
      const double amount, const size_t speed, const size_t year,
      const size_t h, const size_t pass_no
   ):CPlane(Coords(), amount, speed, year, h, pass_no)
   {
   }
   virtual ~CPlane()
   {
   }
   const size_t get_height() const { return height; }
   virtual Type get_type() const { return Type::Plane; }
private:
   size_t height;
};
 
class CShip: public CVehicle, public IPassNumber
{
public:
   CShip
   (
      const Coords& coords, const double amount, const size_t speed, const size_t year,
      const size_t pass_no, const std::string& p
   ):CVehicle(coords, amount, speed, year), IPassNumber(pass_no), port(p)
   {
   }
   CShip
   (
      const double amount, const size_t speed, const size_t year,
      const size_t pass_no, const std::string& p
   ):CShip(Coords(), amount, speed, year, pass_no, p)
   {
   }
   virtual ~CShip()
   {
   }
   const std::string& get_port() const { return port; }
   virtual Type get_type() const { return Type::Ship; }
private:
   std::string port;
};
 
class CCar : public CVehicle
{
public:
   CCar
   (const Coords& coords, const double amount, const size_t speed, const size_t year):
   CVehicle(coords, amount, speed, year)
   {
   }
   CCar(const double amount, const size_t speed, const size_t year):
   CCar(Coords(), amount, speed, year)
   {
   }
   virtual ~CCar()
   {
   }
   virtual Type get_type() const { return Type::Car; }
};
 
typedef std::shared_ptr<CVehicle> base_t;
 
int main()
{
   std::list<base_t> lst = 
   {
      base_t(new CCar(100, 300, 1990)),
      base_t(new CShip(1000, 200, 1990, 1000, "MOW")),
      base_t(new CPlane(1000, 200, 1990, 10000, 500))
   };
   std::for_each(lst.begin(), lst.end(), [](const base_t& value)
   {
      const CVehicle::Coords& coords = value->get_coords();
      std::cout << "Координаты: " << coords.x << " " << coords.y << std::endl;
      std::cout << "Скорость: " << value->get_speed()
       << " Количество пассажиров: " << value->get_amount()
       << " Год выпуска: " << value->get_year() << std::endl;
   });   
   std::list<base_t>::iterator iter = lst.begin();
   ++iter;
   CShip* ship = dynamic_cast<CShip*>(iter->get());
   std::cout << "Номер пассажиров: " << ship->get_pass_no() << " Порт: " << ship->get_port() << std::endl;
   ++iter;
   CPlane* plane = dynamic_cast<CPlane*>(iter->get());
   std::cout << "Номер пассажиров: " << plane->get_pass_no() << " Высота: " << plane->get_height() << std::endl;
}
