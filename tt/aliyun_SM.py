#!/usr/bin/env python
#coding=utf-8

from aliyunsdkcore.client import AcsClient
from aliyunsdkcore.request import CommonRequest

def sendSMS(nums,code):
    client = AcsClient(
                'accesskey1',
                'accesskey2',
				'cn-shanghai')

    request = CommonRequest()
    request.set_accept_format('json')
    request.set_domain('dysmsapi.aliyuncs.com')
    request.set_method('POST')
    request.set_protocol_type('https') # https | http
    request.set_version('2017-05-25')
    request.set_action_name('SendSms')

    request.add_query_param('RegionId', "cn-shanghai")
    request.add_query_param('PhoneNumbers', nums)
    request.add_query_param('SignName', "xx公司")
    request.add_query_param('TemplateCode', "SMS_202815051")
    request.add_query_param('TemplateParam', code)

    response = client.do_action(request)
    print(str(response, encoding = 'utf-8'))
