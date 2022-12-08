using namespace std;
#include<stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <locale.h>
#include"Window.h"
#include"Circle.h"
#include"Line.h"
#include "Queue.h"
#include "Element.h"

#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)

int main() {
    setlocale(LC_ALL, "Portuguese");

    Queue queue;
    Element* e;

    std::vector<Point> pointList;

    Window window;
    HWND windowId;
    printf("??Programa que utiliza outra janela para os resultados:??\n");
    if (window.Create("Circles' My Window")) {
        if ((windowId = window.GetWindowId()) != NULL) {
            MSG msg;
            while (GetMessage(&msg, 0, 0, 0)) {
                DispatchMessage(&msg);
                if (window.HasClicked()) {
                    printf("\nAs coordenadas do seu click são: (%d, %d)\n", window.GetPoint().GetX(), window.GetPoint().GetY());

                    //Para fazer o dessenho
                    Point ponto(window.GetPoint().GetX(), window.GetPoint().GetY());
                    
                    //Adicionar os postos a uma lista
                    Circle circle(ponto, 5);
                    e = new Element();
                    e->read();
                    queue.put(e);
                    circle.Draw(windowId, VERDE);
                    pointList.push_back(ponto);
                    // Para ligar os dois pontos
                    
                    if(pointList.size() > 1) 
                    for (int i = 0; i < pointList.size()-1; i++) {
                            if (i % 2 == 0 || i == 0) {
                                Line line(pointList[i], pointList[i+1]);
                                line.Draw(windowId, VERMELHO, pointList, i);
                        }
                    }
                }
            }
        }
    }
}