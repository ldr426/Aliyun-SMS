#include "sendsms_py.h"
using namespace std;

int SendSMS_PY(QString num,QString code){
    Py_Initialize();
    if ( !Py_IsInitialized() )
    {
    return -1;
    }
    PyObject* pModule = PyImport_ImportModule("aliyun_SM");  // 这里就是创建的python文件
    if (!pModule) {
            cout<< "Cant open python file!\n" << endl;
            return -1;
        }
   PyObject* pFunAli= PyObject_GetAttrString(pModule,"sendSMS");  // 这里的sendSMS就是python文件定义的函数

    if(!pFunAli){
        cout<<"Get function failed"<<endl;
        return -1;
    }


    std::string str = num.toStdString();
    const char* num_ch = str.c_str();


    std::string str2 = code.toStdString();
    const char* code_ch = str2.c_str();

   PyObject* args = PyTuple_New(2);   // 2个参数
   args= Py_BuildValue("ss",num_ch,code_ch);

   PyObject* pRet = PyObject_CallObject(pFunAli, args);

   // 获取参数
   if (pRet)  // 验证是否调用成功
    {
        long result = PyLong_AsLong(pRet);
        cout<< "result:" << result;
    }
    else{
      return -1;
   }
   Py_Finalize();


}
