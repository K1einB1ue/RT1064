/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ͫ����ͷ(SCC8660) RT FLEXIO�ӿ�
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598 & QQ2380006440)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.32.4 or MDK 5.24 �����
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-09-04
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SDA(����ͷ��RX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_TX�궨��
						SCL(����ͷ��TX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_RX�궨��
                        ���ж�(VSY)         �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_VSYNC_PIN�궨��
						���ж�(HREF)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_HREF_PIN�궨��
						�����ж�(PCLK)      �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_PCLK_PIN�궨��
						���ݿ�(D0-D7)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_DATA_PIN�궨��
					------------------------------------ 
	
					Ĭ�Ϸֱ���               160*120
					Ĭ��FPS                  50֡
 ********************************************************************************************************************/



#ifndef _SEEKFREE_SCC8660_h
#define _SEEKFREE_SCC8660_h


#include "common.h"
#include "zf_uart.h"



//Ĭ��ͼ��ֱ���Ϊ160*120��������ͼ��ֱ��ʱ�Ĭ�Ϸֱ��ʴ�����.c�ļ��ڸ���ͼ�񻺳�������λ��ΪSDRAM��������������


//------------ ����ϸ����ע�ͺ��ٸ��ķֱ��� ------------
//------------ ����ϸ����ע�ͺ��ٸ��ķֱ��� ------------
//------------ ����ϸ����ע�ͺ��ٸ��ķֱ��� ------------
//ʹ��flexio�ɼ�ʱ��Ҫ�Ƽ������ֱ���һ����160*120 ��һ����320*240
//���ֱ�������Ϊ320*240��ʱ�������н�zf_camera.c�ļ��е�FLEXIO_SHIFT_COUNT�궨���޸�Ϊ2

#define SCC8660_PIC_W           160		            //ʵ��ͼ��ֱ��ʿ���	��ѡ����Ϊ��160 180 240 320 360 480 640��
#define SCC8660_PIC_H           120		            //ʵ��ͼ��ֱ��ʸ߶�	��ѡ����Ϊ��120 160 180 240 320 360 480��

#define SCC8660_W		        SCC8660_PIC_W*2		//�˲���Ϊͼ�����ݴ洢���� �����޸�
#define SCC8660_H		        SCC8660_PIC_H       //�˲���Ϊͼ�����ݴ洢�߶� �����޸�

//--------------------------------------------------------------------------------------------------
//��������
//--------------------------------------------------------------------------------------------------
#define SCC8660_COF_UART        USART_4             //��������ͷ��ʹ�õ��Ĵ���     
#define SCC8660_COF_UART_TX     UART4_TX_C16
#define SCC8660_COF_UART_RX     UART4_RX_C17

#define SCC8660_VSYNC_PIN       C7                  //���ж�����
#define SCC8660_VSYNC_IRQN      GPIO2_Combined_0_15_IRQn   //�жϺ�


#define SCC8660_DATA_PIN        FLEXIO2_D08_C8      //����D0��������  ����D0����ΪFLEXIO2_D08_C8 ��ôD1��ʹ�õ�������ΪFLEXIO2_D09_C9����������
#define SCC8660_PCLK_PIN        FLEXIO2_D05_C5      //��������ʱ������
#define SCC8660_HREF_PIN        FLEXIO2_D06_C6      //�������ź�����




extern uint16 scc8660_image[SCC8660_PIC_H][SCC8660_PIC_W];
extern uint8  scc8660_finish_flag;                  //һ��ͼ��ɼ���ɱ�־λ


void scc8660_init(void);
void scc8660_vsync(void);
void scc8660_dma(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);


#endif