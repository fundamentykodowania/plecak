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
    Element(std::string nazwa, float cena, float waga){
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
    //wstawianie elementów do spakowania

    //Sortowanie po wadze za 1 kg

    //Wkladanie do plecaka
    
    return 0;
}
