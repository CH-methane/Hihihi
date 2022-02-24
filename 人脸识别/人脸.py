import cv2
import numpy as np 
#人脸识别分类器
facecascade=cv2.CascadeClassifier(r'haarcascade_frontalface_default.xml')
#识别眼睛的分类器
eyecascade=cv2.CascadeClassifier(r'haarcascade_eye.xml')
#main code
cap=cv2.VideoCapture("test.mp4")
cv2.namedWindow('test',cv2.WINDOW_AUTOSIZE)
ok = True
while ok:
    ok,img=cap.read()
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces=facecascade.detectMultiScale(
    	gray,
    	scaleFactor=1.2,
    	minNeighbors=5,
    	minSize=(32,32)
     )
    result=[]
    for(x,y,w,h) in faces:
    	face_gray=gray[y:(y+h),x:(x+w)]
    	eyes=eyecascade.detectMultiScale(face_gray,1.3,2)
    	for(ex,ey,ew,eh) in eyes:
    		result.append((x+ex,y+ey,ew,eh))
    for(x,y,w,h) in faces:
    	cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
    for(ex,ey,ew,eh) in result:
    	cv2.rectangle(img,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
    cv2.imshow('test',img)
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
    ok,img=cap.read()
cap.release()
cv2.destroyAllWindows()