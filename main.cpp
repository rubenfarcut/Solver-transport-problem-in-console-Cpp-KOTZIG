#include <iostream>
using namespace std;
int main()
{   int n,m;
//citim datele
    cout << "---Introduceti tabelul costurilor si cantitatea disponibila/necesara---\n";
    cout<<"Numarul de linii este:";cin>>n;
    cout<<"Numarul de coloane este:";cin>>m;
    float tabel[n+1][m+1],media_randuri[n],media_coloane[m];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cout<<"elemen["<<i<<"]["<<j<<"]:";
            cin>>tabel[i][j];
        }
        n--;m--;
        //calculam media pe randuri
    for(int i=1;i<=n;i++)
       {    media_randuri[i]=0;
            for(int j=1;j<=m;j++)
            media_randuri[i]+=tabel[i][j];
            media_randuri[i]/=m;
        }
        //calculam media pe coloane
    for(int j=1;j<=m;j++)
    {
        media_coloane[j]=0;
        for(int i=1;i<=n;i++)
            media_coloane[j]+=tabel[i][j];
        media_coloane[j]/=n;
    }
  //construim tabelul Kotzig
  float tabel_Kotzig[n+1][m+1];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
  {
      tabel_Kotzig[i][j]=media_coloane[j]+media_randuri[i]-tabel[i][j];
  }
  //Afisam tabelul initial
  cout<<"---Tabelul initial---\n";
  for(int i=1;i<=n+1;i++)
  {for(int j=1;j<=m+1;j++)
  cout<<tabel[i][j]<<" ";
  cout<<endl;
  }
//Afisam tabelul Kotzig
cout<<"---Tabelul Kotzig ajutator---\n";
  for(int i=1;i<=n;i++)
  {for(int j=1;j<=m;j++)
  cout<<tabel_Kotzig[i][j]<<" ";
  cout<<endl;
  }
  float tabel_distribuire[n+1][m+1],maxim=tabel_Kotzig[1][1];
for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
    tabel_distribuire[i][j]=0;
//distribuim cantitatile disponibile beneficiarilor
while(maxim!=0)
{maxim=0;
    for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
    if(tabel_Kotzig[i][j]>=maxim)
       {maxim=tabel_Kotzig[i][j];}
    for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  if(tabel_Kotzig[i][j]==maxim)
  {

tabel_Kotzig[i][j]=0;

if(tabel[i][m+1]<tabel[n+1][j]&&tabel[i][m+1]*tabel[n+1][j]!=0)
{
tabel_distribuire[i][j]=tabel[i][m+1];
tabel[n+1][j]-=tabel[i][m+1];
tabel[i][m+1]=0;
}
 else if(tabel[i][m+1]>tabel[n+1][j]&&tabel[i][m+1]*tabel[n+1][j]!=0)
 {
    tabel_distribuire[i][j]=tabel[n+1][j];
tabel[i][m+1]-=tabel[n+1][j];
tabel[n+1][j]=0;

 }
else if(tabel[i][m+1]==tabel[n+1][j]&&tabel[i][m+1]*tabel[n+1][j]!=0)
{
    tabel_distribuire[i][j]=tabel[i][m+1];
tabel[i][m+1]=0;
tabel[n+1][j]=0;
}
i=n+1;j=m+1;
  }
}

//Afisam solutia
cout<<"---Tabelul solutiei---\n";
  for(int i=1;i<=n;i++)
  {for(int j=1;j<=m;j++)
  cout<<tabel_distribuire[i][j]<<" ";
  cout<<endl;
  }
    return 0;
}
