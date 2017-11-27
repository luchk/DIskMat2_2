#include <iostream>
#include <algorithm>
using namespace std;


void swap(int *a, int i, int j)
{
    int s=a[i];
    a[i]=a[j];
    a[j]=s;
}
void show (int *a,int n)
{
    static int num=0;
    //cout.width (3);
    cout << num++ <<":";
    for (int i=0;i<n;i++)
    {
        cout << a[i]<<" ";
    }
    cout<<endl;
}

bool GenP(int *a,int n)
{
    int j=n-2;
    while (j!=-1 && a[j]>=a[j+1])j--;
    if (j==-1)
    {
        return false;
    }
    int k=n-1;
    while (a[j]>=a[k])k--;
    swap(a,j,k);
    int l=j+1;
    int r=n-1;
    while (l<r)
    {
        swap(a,l++,r--);
    }
    return true;
}
bool GenC(int *a, int f, int r)
{
    for (int i=r-1;i>=0;i--)
    {
        if(a[i]!=f-r+i+1)
        {
            a[i]=a[i]+1;
            for(int j=i+1;j<r-1;j++)
            {
                a[j]=a[j-1]+1;
            }
            return true;
        }
    }
}





int main()
{
    int b;
    cout<<"if choose genp press 0";
    cout<<endl;
    cout<<"if choose genc press 2";
    cout<<endl;
    cin>>b;

    int n;
    cout << "введіть кількість чисел для формування перестановок";
    cin >> n;

        if (b<1)
            {
                int a[n];
//                for (int j = 0; j <n ; ++j)  //використовувати у випадку якщо потрібно генерувати перестановки з послідовними числами тобто 1 2 3 4 5 6, коли вони точно мають йти одні з одними і це відомо заздалегідь
//                {
//                    a[j] = j+1;
//                }

                for (int k = 0; k < n; ++k)
                {
                    cin >> a[k];
                }
                show(a,n);
//                sort(a+0,a+n); //використовувати якщо перед початкому генерації потрібно відсортувати елементи
//                show(a,n);
                while (GenP(a, n))
                    show(a, n);
            }
            else if (b>1)
            {
                const int n=4;
                int f=6;
                int r=4;
                int a[n]={1,3,2,4};

                show(a,n);
                sort(a+0,a+n);
                show(a,n);
                for(int i=2;i<=100;i++)
                    {
                        GenC(a,f,r);
                        show(a,r);
                    }
                return 0;
            }
    return 0;
}
