#include <iostream>
#include <string>
using namespace std;
string matriz [22][22];
void print(int n,int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<matriz[i][j]<<" ";
				}
			cout<<endl;
			}
	
	}
void puntos(string prev,float& cont,int pasos){
	if(prev=="*"){
		cont+=2;
		}
	if(prev=="#"){
		cont+=1;
		}
	if(prev=="@"){
		cont+=1.5;
		}
	if(prev=="S" && pasos==0){
		cont+=1;
		}
	
}
int main(){
	float cont=0;
	int n,m,pasos,x,y,x1,y1;
	string direc,prev;
	cin>>n>>m;
	//ingresar caracteres del mapa. # @ # / # # @ R # * * # # # * @ / S * * * # * @ # # @ @ # *
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matriz[i][j];
			if(matriz[i][j]=="R"){
				x= i; x1= i;
				y= j; y1= j;
			}
		}
	}
	print(n,m);
	//pasos y direccion
	while(prev!="S"){
	cin>>direc>>pasos;
		while(pasos!=0){
			if(direc=="N"){
				matriz[x][y]=prev;
				x--;
				if(x<0){
					x++;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					x++;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="S"){
				matriz[x][y]=prev;
				x++;
				if(x>(n-1)){
					x--;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					x--;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="E"){
				matriz[x][y]=prev;
				y++;
				if(y>(m-1)){
					y--;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y--;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
				
				
			}
			if(direc=="O"){
				matriz[x][y]=prev;
				y--;
				if(y<0){
					y++;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y++;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="NE"){
				matriz[x][y]=prev;
				y++; x--;
				if(x<0 && y<(m-1)){
					y--; x++;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y--; x++;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="NO"){
				matriz[x][y]=prev;
				y--; x--;
				if(y<0 && x<(n-1)){
					y++; x++;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y++; x++;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="SE"){
				matriz[x][y]=prev;
				y++; x++;
				if(x>(n-1) && y>(m-1)){
					y--; x--;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y--; x--;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
			if(direc=="SO"){
				matriz[x][y]=prev;
				y--; x++;
				if(x>0 && y<(m-1)){
					y++; x--;
					matriz[x][y]="R";
					goto afuera;
					}
				prev=matriz[x][y];
				if(prev=="/"){
					y++; x--;
					prev=matriz[x][y];
					matriz[x][y]="R";
					break;	
				}
				matriz[x][y]="R";
				pasos--;
				if(cont==0){
					matriz[x1][y1]="#";
				}
			}
		puntos(prev,cont,pasos);
		}
		afuera:
		if(prev!="S"){		
			print(n,m);
			cout<<"acumulado: "<<cont<<endl;
		}
		else{
			cout<<"Ha llegado y su acumulado total es "<<cont<<endl;
		}
	}
return 0;
}

