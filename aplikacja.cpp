#include<iostream>
#include<string>
#include<vector>

class Element
{
    private:
        std::string nazwa;
        float cena;
        float waga;
        float wagaZaKG;
    public:    
    void setElement(std::string nazwa, float cena, float waga){
        this->nazwa=nazwa;
        this->waga=waga;
        this->cena=cena;
        wagaZaKG=cena/waga;
    };
    std::string getNazwa(){
            return nazwa;}

    float getCena(){
        return cena;
    }
    float getWaga(){
        return waga;
    }
    float getWagaZaKG(){
        return wagaZaKG;
    }
    
};

class Plecak{
    private:
        std::vector <Element> zawartoscPlecaka;
        int nosnosc;
    public:
        bool dodajElement(Element element){
            if(nosnosc<=element.getWaga()){
                zawartoscPlecaka.push_back(element);
                nosnosc=nosnosc-element.getWaga();
                return true;} 
            else 
                return false;

        }
    Plecak(int nosnosc){
        this->nosnosc=nosnosc;
    }    
    int getNosnosc(){
        return nosnosc;
    }

};

//_____________________________________________________________
int main(int argc, char const *argv[])
{
    std::vector <Element> naStole;
    Element element;
    std::string nazwa;
    float cena,waga;
    //wstawianie elementów do spakowania
        do{
            std::cout<<"-----------"<<std::endl<<"podaj nazwe:";
            std::cin>>nazwa;
            if(nazwa!="."){
                std::cout<<"podaj cene:";
                std::cin>>cena;
                std::cout<<"podaj wage:";
                std::cin>>waga;
                element.setElement(nazwa, cena, waga);
                naStole.push_back(element);
            };
        }while(nazwa!=".");
    //Sortowanie po wadze za 1 kg

    //Wkladanie do plecaka

    return 0;
};
