#include <iostream>

using namespace std;

int ile;
int obzartuchy, sztuki;
int pudelka;
int ciastka;


int main()
{
    cin>>ile;

    for (int i=0; i<ile; i++)
    {
        cin>>obzartuchy>>sztuki;

        int czas[obzartuchy];
        ciastka = 0;

        for (int i = 0; i<obzartuchy; i++)
        {
            cin>>czas[i];
            ciastka += (86400/czas[i]);

        }
        if (ciastka%sztuki == 0)
        {
            pudelka = (ciastka/sztuki);
            cout<<pudelka<<endl;
        }
        else
        {
            pudelka = ((ciastka/sztuki)+1);
            cout<<pudelka<<endl;
        }
    }




    return 0;
}
