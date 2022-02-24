from __future__ import division
import numpy as np
import pandas as pd
import joblib
import matplotlib.pyplot as plt;
from sklearn import preprocessing
from sklearn.svm import SVC
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split



if __name__ == '__main__':
	data=pd.read_csv("data.csv",header = None)
	data=data.dropna()
	data=shuffle(data)#随机排列顺序
	data=data.drop([0])
	lab=data[29]
	data=data.drop([0],axis=1)
	data=data.drop([29],axis=1)
	data_scaled = preprocessing.scale(data)#零-均值规范化
	lab=lab.values
	data_train, data_test, lab_train, lab_test = train_test_split(data_scaled, lab, random_state=1, train_size=0.9)
	score = []
	gamma_range = np.logspace(-10, 1, 50) #返回在对数刻度上均匀间隔的数字
	for i in gamma_range:
		clf = SVC(kernel="rbf",C=80,gamma = i,cache_size=5000).fit(data_train,lab_train)
		score.append(clf.score(data_test,lab_test))
	print(max(score), gamma_range[score.index(max(score))])
	plt.plot(gamma_range,score)
	plt.show()
	#lr = SVC(kernel='linear',C=100).fit(data_train,lab_train)
	print("SVM-输出训练集的准确率为：",lr.score(data_train,lab_train))
	print("SVM-输出测试集的准确率为：",lr.score(data_test,lab_test))
	joblib.dump(clf,'CGPG.model')