#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using std::string;

class Sale{
public:
    Sale(string city, string product, double price, size_t quantity) 
        : city(city), product(product), profit(price * quantity) {}
    
    string getCity() const { return city; }

    void addProfit(double newProfit){
        profit += newProfit;
    }
    double getProfit() const { return profit; }

private:
    string city;
    string product;
    double profit;
};

class SalesContainer{
public:
    SalesContainer() {}
    void addSale(Sale& goalSale){
        for (Sale& sale : container){
            if (sale.getCity() == goalSale.getCity()){
                sale.addProfit(goalSale.getProfit());
                return;
            }
        }
        container.push_back(goalSale);
    }
    void getTotalSales(){
        std::sort(container.begin(), container.end(), 
            [](const Sale& a, const Sale& b){
                return a.getCity() < b.getCity(); 
            });
    
    std::cout << std::fixed << std::setprecision(2);
    for (Sale& sale : container){
        std::cout << sale.getCity() << " -> "
        << sale.getProfit() << '\n';
        }
    }
private:
    size_t size;
    std::vector<Sale> container;
};

class SalesRegister{
public: 
    SalesRegister(std::istream& stream){
        size_t amount;
        std::cin >> amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < amount; ++i){
            string line;
            getline(stream, line);
            std::istringstream iss(line);

            string city;
            string product;
            double price;
            size_t quantity;

            iss >> city >> product >> price >> quantity;
            Sale currentSale(city, product, price, quantity);
            sc.addSale(currentSale);
        }
    }
    void getTotalSales(){
        sc.getTotalSales();
    }
private:
    SalesContainer sc;
};

int main(){
    SalesRegister sr(std::cin);
    sr.getTotalSales();
}