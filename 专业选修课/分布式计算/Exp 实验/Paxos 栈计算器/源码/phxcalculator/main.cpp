/*
Tencent is pleased to support the open source community by making 
PhxPaxos available.
Copyright (C) 2016 THL A29 Limited, a Tencent company. 
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may 
not use this file except in compliance with the License. You may 
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
implied. See the License for the specific language governing 
permissions and limitations under the License.

See the AUTHORS file for names of contributors. 
*/

#include "calculator_server.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "phxpaxos/options.h"

using namespace phxpaxos;
using namespace std;

int parse_ipport(const char * pcStr, NodeInfo & oNodeInfo)
{
    char sIP[32] = {0};
    int iPort = -1;

    int count = sscanf(pcStr, "%[^':']:%d", sIP, &iPort);
    if (count != 2)
    {
        return -1;
    }

    oNodeInfo.SetIPPort(sIP, iPort);

    return 0;
}

int parse_ipport_list(const char * pcStr, NodeInfoList & vecNodeInfoList)
{
    string sTmpStr;
    int iStrLen = strlen(pcStr);

    for (int i = 0; i < iStrLen; i++)
    {
        if (pcStr[i] == ',' || i == iStrLen - 1)
        {
            if (i == iStrLen - 1 && pcStr[i] != ',')
            {
                sTmpStr += pcStr[i];
            }
            
            NodeInfo oNodeInfo;
            int ret = parse_ipport(sTmpStr.c_str(), oNodeInfo);
            if (ret != 0)
            {
                return ret;
            }

            vecNodeInfoList.push_back(oNodeInfo);

            sTmpStr = "";
        }
        else
        {
            sTmpStr += pcStr[i];
        }
    }

    return 0;
}
int main(int argc, char ** argv) {
    if (argc < 3)
    {
        printf("%s <myip:myport> <node0_ip:node_0port,node1_ip:node_1_port,node2_ip:node2_port,...>\n", argv[0]);
        return -1;
    }
    NodeInfo oMyNode;
    if (parse_ipport(argv[1], oMyNode) != 0)
    {
        printf("parse myip:myport fail\n");
        return -1;
    }

    NodeInfoList vecNodeInfoList;
    if (parse_ipport_list(argv[2], vecNodeInfoList) != 0)
    {
        printf("parse ip/port list fail\n");
        return -1;
    }

    PhxCalculatorServer calculatorServer(oMyNode, vecNodeInfoList);
    int ret = calculatorServer.RunPaxos();
    if (ret != 0)
    {
        return -1;
    }
    printf("calculator server start, ip %s port %d\n", oMyNode.GetIP().c_str(), oMyNode.GetPort());

    string sUserInput;
    while (true) {
        printf("\n> ");
        getline(cin, sUserInput);
        string sResult;
        ret = calculatorServer.RunCommand(sUserInput, sResult);
        if (ret != 0)
        {
            printf("FAIL!, ret %d\n", ret);
        }
        else
        {
            printf("%s\n", sResult.c_str());
        }
    }
}
/*
int main_old(int argc, char ** argv)
{
    if (argc < 3)
    {
        printf("%s <myip:myport> <node0_ip:node_0port,node1_ip:node_1_port,node2_ip:node2_port,...>\n", argv[0]);
        return -1;
    }

    NodeInfo oMyNode;
    if (parse_ipport(argv[1], oMyNode) != 0)
    {
        printf("parse myip:myport fail\n");
        return -1;
    }

    NodeInfoList vecNodeInfoList;
    if (parse_ipport_list(argv[2], vecNodeInfoList) != 0)
    {
        printf("parse ip/port list fail\n");
        return -1;
    }

    PhxEchoServer oEchoServer(oMyNode, vecNodeInfoList);
    int ret = oEchoServer.RunPaxos();
    if (ret != 0)
    {
        return -1;
    }
    printf("echo server start, ip %s port %d\n", oMyNode.GetIP().c_str(), oMyNode.GetPort());

    string sEchoReqValue;
    while (true)
    {
        printf("\nplease input: <echo req value>\n");
        getline(cin, sEchoReqValue);
        string sEchoRespValue;
        ret = oEchoServer.Echo(sEchoReqValue, sEchoRespValue);
        if (ret != 0)
        {
            printf("Echo fail, ret %d\n", ret);
        }
        else
        {
            printf("echo resp value %s\n", sEchoRespValue.c_str());
        }
    }

    return 0;
}
*/
