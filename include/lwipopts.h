/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H__
#define LWIP_HDR_LWIPOPTS_H__

#include <unistd.h>
#include <fcntl.h>
#include <mcu/debug.h>

/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NO_SYS                          0
#define LWIP_NETCONN                    1
#define LWIP_DNS                        1
#define LWIP_SOCKET                     1
#define LWIP_COMPAT_MUTEX_ALLOWED       1
#define MEM_LIBC_MALLOC                 1
#define MEM_ALIGNMENT                   4
#define ETH_PAD_SIZE                    2
#define LWIP_SOCKET_OFFSET			   OPEN_MAX

#define LWIP_POSIX_SOCKETS_IO_NAMES     0
#define LWIP_COMPAT_SOCKETS             0
#define LWIP_NETIF_HOSTNAME             1

#define LWIP_IPV6                       1
#define IPV6_FRAG_COPYHEADER            1
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0
#define LWIP_DHCP_CHECK_LINK_UP         1


/* Enable DHCP to test it */
#define LWIP_DHCP                       1

#if defined MCU_DEBUG
#define LWIP_DEBUG 1

//#define ETHARP_DEBUG 0x80
#define TCPIP_DEBUG 0x80
#define TCP_DEBUG 0x80
#define TCP_INPUT_DEBUG 0x80
#define TRACE_DEBUG 0x80
#define SOCKETS_DEBUG 0x80
#define UDP_DEBUG 0x80
#define DHCP_DEBUG 0x80
#define AUTOIP_DEBUG 0x80
#define API_LIB_DEBUG 0x80
#define API_MSG_DEBUG 0x80
//#define NETIF_DEBUG 0x80
#define IP_DEBUG 0x80
#define TCP_CWND_DEBUG 0x80
#define SOCKETS_DEBUG 0x80
//#define PBUF_DEBUG 0x80
#define LWIP_DBG_MIN_LEVEL 0

#endif

/* Checksum settings */
#define CHECKSUM_GEN_IP 0
#define CHECKSUM_GEN_UDP 0
#define CHECKSUM_GEN_TCP 0
#define CHECKSUM_GEN_ICMP 0
#define CHECKSUM_GEN_ICMP6 0
#define CHECKSUM_CHECK_IP 1
#define CHECKSUM_CHECK_UDP 1
#define CHECKSUM_CHECK_TCP 1
#define CHECKSUM_CHECK_ICMP 1
#define CHECKSUM_CHECK_ICMP6 1

/* Minimal changes to opt.h required for tcp unit tests: */
#define MEM_SIZE                        1600
#define TCP_SND_QUEUELEN                40
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
#define TCP_SND_BUF                     (12 * TCP_MSS)
#define TCP_WND                         (10 * TCP_MSS)
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   0
#define PBUF_POOL_SIZE                  16

#define TCPIP_THREAD_STACKSIZE          2048

/* Minimal changes to opt.h required for etharp unit tests: */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1


#endif /* LWIP_HDR_LWIPOPTS_H__ */
