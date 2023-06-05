import cv2
import numpy as np

def mouse_clic(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONUP:
        src = param.copy()

        cv2.floodFill(src, None, (x, y), (0, 255, 255))
        cv2.imshow('Fill zone', src)

def main():
    winname = 'Flood fill'
    img = cv2.imread('opencv-logo.png')

    cv2.namedWindow(winname)
    cv2.setMouseCallback(winname, mouse_clic, img)

    while(1):
        cv2.imshow(winname, img)
        if cv2.waitKey(20) & 0xFF == 27:
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
