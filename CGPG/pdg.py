from __future__ import division
import numpy as np
import pywt
import cv2
import csv
import os
from sklearn.utils import shuffle


'''def erfen(nd,abnd,test):
	ndata=nd
	abndata=abnd
	ndata['label']=0
	abndata['label']=1'''
def dataget(coeff):
	c=[i for arr in coeff for i in arr]
	mean=np.mean(c)
	var=np.var(c)
	skew=np.mean((c-mean)**3)/pow(var,3)
	kurt=np.mean((c-mean)**4)/pow(var,4)
	return mean,var,skew,kurt

if __name__ == '__main__':
	path="D:/xunleixiazei/for python/bishe/database/train"
	af = [f for f in os.listdir(path)]#输出根path下的所有文件名到一个列表中
	af=shuffle(af)#随机排列顺序
	for file in af:
		print(file)
		p=path+"/"+file
		#img=cv2.imdecode(np.fromfile(p,dtype=np.uint8),3)
		img=cv2.imread(p,3)
		if img is None:
			continue
		img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
		img = cv2.GaussianBlur(img,(5,5),0) # 用高斯平滑处理原图像降噪。若效果不好可调节高斯核大小
		canny = cv2.Canny(img, 30, 150)     # 调用Canny函数，指定最大和最小阈值，其中apertureSize默认为3。
		'''cv2.imshow('test', img)
		cv2.waitKey(0)
		cv2.destroyAllWindows()'''
		coeff = pywt.wavedec2(canny, 'haar', level=2)
		x=[]
		x.append(coeff[1])
		x.append(coeff[2])
		c=[i for arr in x for i in arr]
		c.append(coeff[0])
		#cH2, cV2, cD2, cH1, cV1, cD1,cA2
		tocsv=[file]
		for cc in c:
			mean,var,skew,kurt=dataget(cc)
			tocsv.append(mean)
			tocsv.append(var)
			tocsv.append(skew)
			tocsv.append(kurt)
		find1="CG"
		find2="PG"
		if(find1 in file):
			tocsv.append(0)
		if(find2 in file):
			tocsv.append(1)
		with open("data.csv","a+", newline='') as csvfile:
			writer = csv.writer(csvfile)
			#先写入columns_name
			'''writer.writerow(["filename","cH2m","cH2v","cH2s","cH2k"
				,"cV2m","cV2v","cV2s","cV2k"
				,"cD2m","cD2v","cD2s","cD2k"
				,"cH1m","cH1v","cH1s","cH1k"
				,"cV1m","cV1v","cV1s","cV1k"
				,"cD1m","cD1v","cD1s","cD1k"
				,"cA2m","cA2v","cA2s","cA2k","lab"])'''
			writer.writerow(tocsv)
			#写入多行用writerows
			#writer.writerows([[0,1,3],[1,2,3],[2,3,4]])
		print("done")
