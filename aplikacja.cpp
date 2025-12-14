#include<iostream>
#include<string>
#include<vector>

class Element
{
 private:
        std::string nazwa;
        float cena;
        float waga;
        float cenaZaKG;
 public:  
    Element(std::string nazwa, float cena, float waga){
        this->nazwa=nazwa;
        this->waga=waga;
        this->cena=cena;
        cenaZaKG=cena/waga;
    };
       
    std::string getNazwa(){
            return nazwa;}

    float getCena(){
        return cena;
    }
    float getWaga(){
        return waga;
    }
    float getCenaZaKG(){
        return cenaZaKG;
    }   
};

class Plecak{
    private:
        std::vector <Element*> zawartoscPlecaka;
        float pozostalaNosnosc;
        float nosnosc;
    public:
        bool dodajElement(Element* element){
            if(pozostalaNosnosc>=element->getWaga()){
                zawartoscPlecaka.push_back(element);
                pozostalaNosnosc=pozostalaNosnosc-element->getWaga();
                return true;} 
            else 
                return false;

        }
    Plecak(int nosnosc){
        this->nosnosc = nosnosc;
        pozostalaNosnosc = nosnosc;
    }    
    int getPozostalaNosnosc(){
        return pozostalaNosnosc;
    }
    
};

//_____________________________________________________________
int main(int argc, char const *argv[])
{
    std::vector <Element*> naStole;

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
                naStole.push_back(new Element(nazwa, cena, waga));
            };
        }while(nazwa!=".");

    //Sortowanie po cenie za 1 kg
    int ileDoSpakowania = naStole.size();
    bool flaga;
    do{
        flaga = false;
        for(int j=0; j<ileDoSpakowania-1; j++)
            if(naStole[j]->getCenaZaKG() < naStole[j+1]->getCenaZaKG()){
                std::swap(naStole[j], naStole[j+1]);
                flaga = true;
            }
    } while (flaga);
       
    //Wkladanie do plecaka

    Plecak plecak(10.0f);

    for(Element* n: naStole){
        if(n->getWaga() < plecak.getPozostalaNosnosc())
        plecak.dodajElement(n);
    }



    for(Element* n: naStole){
       delete(n);
    }

    return 0;
};
