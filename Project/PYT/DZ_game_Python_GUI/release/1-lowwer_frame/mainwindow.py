# -*- coding: UTF-8 -*-

from tkinter import *
import random
import time
from datetime import datetime
import os

# ---------------------------check---------------------------

#�鿴


def check(index:str, commit:str) -> list:
    # ������Ҫһ����¼ԭ���ַ�������
    aclen = 0.0
    celen = 0.0
    zql = 0.0 #��ȷ��
    # ѭ������
    for i, j in zip(index, commit):
        if i == j:
            aclen += 1.0
        else:
            celen += 1.0
    zql = float(aclen / 50) * 100.0

    ainfo = [zql, aclen, celen]
    return ainfo
# ---------------------------check---------------------------


constin = None  # �������changliang
cyongshi = None  # ��ʱ
timestrS = datetime.utcnow()  # ʱ���¼��-first
timestrLast = 0  # ʱ���¼��-last
chstr = None

ft = r"E:\ProgramThomas\Coding-Notes\Project\PYT\������ϷPython��GUI����\resource\loggerstr.log"
'''
def msgShow():
    label["text"] = 'I Love Python'
    label["bg"] = 'orangerad'
'''


def getStr(ent):
    global constin
    # ����Entry��ֵ
    tmp = ent.get()
    constin = tmp


def pushStart():
    # timestrS=time.time()
    timestrS = datetime.utcnow()
'''
def itg(chstr, constin):
    #"ʱ��:"+str(cyongshi)+'��'
    ccList = check(chstr, constin)
    endstr = "ʱ��:" + str(cyongshi) + '��' + '\n'
    endstr += '��ȷ��:' + str(ccList[0]) + '\n'
    endstr += '����:' + str(ccList[1]) + '��\n'
    endstr += '����:' + str(ccList[2]) + '��\n'
    return endstr
'''


def pushEnd():
    getStr(intxt)
    global cyongshi
    #fmmf = time.time()
    fmmf = datetime.utcnow()
    #timtmp = fmmf - timestrS
    timtmps = timestrS.second+timestrS.minute*60
    timtmpe = fmmf.second+fmmf.minute*60
    #print("get timestamp this of->time.time()={0}".format(time.time()))
    #print("get timestamp minx of->timtmp={0}".format(timtmp))
    timestrLast = timtmpe - timtmps
    cyongshi = timestrLast

    ccList = check(chstr, constin)
    endstr = "ʱ��:" + str(cyongshi) + '��' + '\n'
    endstr += '��ȷ��:' + str(ccList[0]) + '%\n'
    endstr += '����:' + str(ccList[1]) + '��\n'
    endstr += '����:' + str(ccList[2]) + '��\n'
    #PHOTO IMAGE
    lbot = Label(root, width=50, text=endstr,
             #bitmap='',
             compound='left',
             anchor=SW,
             bg='skyblue')
    lbot.grid()


# --------------------------------
root = Tk()
root.title("������ϷGUI")
root.iconbitmap("iconbitmap.ico")
root.geometry("500x400")  # 779*655
lb = Label(root, bitmap="hourglass",
           compound="left",
           cursor="target",
           text="AC����ͨ",
           fg="blue", bg="yellow",
           anchor=CENTER, font=("Helvetic", 20, "bold")
           )
# r"E:\ProgramThomas\Coding-Notes\Project\PYT\������ϷPython��GUI����\resource\BITMAP_TITLE.ico"
lb2 = Label(root, bitmap="question",
            compound="left",
            text="��ʾ��������Ϸ����� ��ʼ ��ť����ʼ��ʱ������� �ύ ��ť����",
            fg="#FF0000", bg="lightyellow",
            )

characters = []  # 0~26
for i in range(0, 50):
    tmp = random.randint(0, 25)
    characters.append(chr(ord('a') + tmp))

# print(characters)
chstr = ""
for i in characters:
    chstr += i

lbtip = Label(root, bitmap="info",
              compound="left",
              text="����" + chstr,
              fg="green", bg="#cccccc",
              font=("simsun", 12), underline=True)
# Entry cursor circle

INframe = Frame(root, width=70)  # ����������
intxtL = Label(INframe, text="����> ")

intxt = Entry(INframe, width=50, show="*")

btnframe = Frame(root, width=60)
# BUTTON ��ť    ��ʼ�ͽ���
btnStart = Button(btnframe, text="��ʼ����", fg="blue", width=20,
                  command=pushStart)
btnEnd = Button(btnframe, text="�������", fg="blue", width=20,
                command=pushEnd)
btnExit = Button(btnframe, text='�˳�����', fg="red", width=20,
                 command=root.destroy)

#cc = Cac(chstr, constin)   class init to cc var


lb.grid()
lb2.grid()
lbtip.grid()
INframe.grid()
intxtL.grid(row=3, column=0, sticky=W)  # ����>Label
intxt.grid(row=3, column=1)  # �����Entry th
btnframe.grid()


btnStart.grid(row=4, column=0)
btnEnd.grid(row=4, column=1)
btnExit.grid(row=4, column=2)


#lbot.grid()

# textTip = Text(root)
# textTip.pack(fill=BOTH, expand=True, padx=3, pady=2)
# textTip.insert(END, chstr)
root.mainloop()
