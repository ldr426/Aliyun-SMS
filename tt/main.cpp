#include <QCoreApplication>

using namespace std;

#include <sendsms_py.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QString num = "phoneNum";

   QString code = "{code:1243667463}";

   int jud = SendSMS_PY(num,code);
   if(jud==-1){
        cout<<"发送失败/n";
   }

   return a.exec();
}
