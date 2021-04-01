#include "ZombieMonster.hh"

ZombieMonster::ZombieMonster(){
    SetLife(1);
    this->SetX(21);
    this->SetY(14);
    this->direction=haut;
}

ZombieMonster::~ZombieMonster(){
}

//on verifie si on se trouve sur une intersection
bool ZombieMonster::isOnIntersec(int maps[31][28]){
    //Fonction qui vérifie qu'on est sur une intersection
    int g = int(this->GetX()-1);
    int d = int(this->GetX()+1);
    int h = int(this->GetY()-1);
    int b = int(this->GetY()+1);
    int x = int(this->GetX());
    int y = int(this->GetY());

    if ( maps[h][x] != 0  && (maps[y][g] != 0 || maps[y][d]!=0)  ) return true;
    if ( maps[b][x] != 0  && (maps[y][g] != 0 || maps[y][d]!=0) ) return true;
    else return  false;
}

//on change la direction du monstre
//l'objectif est de parcourir la plus longue distance en premier
void ZombieMonster::changeDirection(double adjacent, double oppose) {
    if ( abs(adjacent)>abs(oppose)){
        if (adjacent>0){
            this->direction=droite;
        }
        else if (adjacent<0){
            this->direction=gauche;
        }
    }
    else {
        if (oppose>0){
            this->direction=bas;
        }
        else if (oppose<0){
            this->direction=haut;
        }
    }
}



void ZombieMonster::forceChangeDirection() {
    switch (this->direction) {
        case haut:
        case bas:
            if ( this->reportMove>0) this->direction=droite;
            else this->direction=gauche;
            break;
        case gauche:
        case droite:
            if ( this->reportMove>0) this->direction=bas;
            else this->direction=haut;
            break;
        default:
            std::cout<<"error change direction"<<std::endl;
    }
}


void ZombieMonster::Update(){
    TimeManager &tm = TimeManager::GetInstance();
    this->SetX(this->GetX() + (tm.GetElapsedTime() / 1000.0));
	this->SetY(this->GetY() + (tm.GetElapsedTime() / 1000.0));
}

void ZombieMonster::Bas(int maps[31][28]) {
    if ( maps[int(this->GetY()+1)][int(this->GetX())] != 0)
        this->SetY(this->GetY()+1);
}
void ZombieMonster::Haut(int maps[31][28]) {
    if ( maps[int(this->GetY()-1)][int(this->GetX())] != 0)
        this->SetY(this->GetY()-1);
}

void ZombieMonster::Gauche(int maps[31][28]) {
    if ( maps[int(this->GetY())][int(this->GetX()-1)] != 0)
        this->SetX(this->GetX()-1);
}

void ZombieMonster::Droit(int maps[31][28]) {
    if ( maps[int(this->GetY())][int(this->GetX()+1)] != 0)
        this->SetX(this->GetX()+1);
}


//On deplace le monstre
void ZombieMonster::Mov(Pacman &pacman , int map[31][28],int adjacent , int oppose ){
    if (isOnIntersec(map)){
        if (this->forceMove) {
            forceChangeDirection();
            this->forceMove=false;
        }
        else {
            changeDirection(adjacent,oppose);
        }
    }
    int x = this->GetX();
    int y = this->GetY();
    Avance(map);

    if (x==this->GetX() && y==this->GetY()){//on verifie si le monstre n'a pas bouger
        if (abs(adjacent)>abs(oppose)) changeDirection(0,oppose);
        else changeDirection(adjacent,0);
        Avance(map);
        if (x==this->GetX() && y==this->GetY()){//on verifie si le monstre n'a pas bouger
            forceDeplacement(map,adjacent,oppose);
        }
    }
}


//Lorsque le monstre est coincé dans un coin on force le déplacement
void ZombieMonster::forceDeplacement( int map[31][28], int adjacent, int oppose){
    this->forceMove=true;
    switch (this->direction) {
        case haut:
            if (adjacent<0){
                this->direction=droite;
                this->reportMove=adjacent;
            }
            break;
        case bas:
            if(adjacent>0){
                this->direction=gauche;
                this->reportMove=adjacent;
            }
            break;
        case gauche:
            if (adjacent <0){
                this->direction=bas;
                this->reportMove=oppose;
            }
            break;
        case droite:
            if (adjacent >0) {
                this->direction = gauche;
                this->reportMove=oppose;
            }
            break;
        default:
            std::cout<< "error" <<std::endl;
            break;
    }
    this->Avance(map);
}

//avance d'une case selon la direction du monstre
void ZombieMonster::Avance(int map[31][28] ){
    switch (this->direction) {
        case haut:
            this->Haut(map);
            break;
        case bas:
            this->Bas(map);
            break;
        case gauche:
            this->Gauche(map);
            break;
        case droite:
            this->Droit(map);
            break;
        default:
            std::cout<< "error" <<std::endl;
            break;
    }
}


//Mise en mouvement du monstre
void ZombieMonster::Move(Pacman &pacman , int map[31][28] ){


//Find out the direction (angle) the Ghost needs to move towards
//Using SOH-CAH-TOA trignometic rations
    double opposite=pacman.GetY() - (this->GetY());
    double adjacent=pacman.GetX() - (this->GetX());
    double angle = atan(opposite/adjacent);
    if (this->GetX()  > pacman.GetX()) {
        angle=angle+180;
    }

//Use this angle to calculate the velocity vector of the Ghost
//Once again using SOH-CAH-TOA trignometic rations
    int velocity=3; //pixels per frame

    double vx = velocity * cos(angle);
    double vy = velocity * sin(angle);


  // nextMove(opposite,adjacent,map);
  std::cout<< "adjacent :"<<adjacent<<"  oppose : "<< opposite<<std::endl;

   this->Mov(pacman,map,adjacent,opposite);
    std::cout <<"  ghost jauneX :" << this->GetX() <<"  ; ghost Y : "<<this->GetY() <<std::endl;



}


