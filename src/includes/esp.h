/* Command Register */
#define CMD_DMA      0x80
#define CMD_CMD      0x7f

#define CMD_NOP      0x00
#define CMD_FLUSH    0x01
#define CMD_RESET    0x02
#define CMD_BUSRESET 0x03
#define CMD_TI       0x10
#define CMD_ICCS     0x11
#define CMD_MSGACC   0x12
#define CMD_PAD      0x18
#define CMD_SATN     0x1a
#define CMD_SEL      0x41
#define CMD_SELATN   0x42
#define CMD_SELATNS  0x43
#define CMD_ENSEL    0x44
#define CMD_DISSEL   0x45

#define CMD_SEMSG    0x20
#define CMD_SESTAT   0x21
#define CMD_SEDAT    0x22
#define CMD_DISSEQ   0x23
#define CMD_TERMSEQ  0x24
#define CMD_TCCS     0x25
#define CMD_DIS      0x27
#define CMD_RMSGSEQ  0x28
#define CMD_RCOMM    0x29
#define CMD_RDATA    0x2A
#define CMD_RCSEQ    0x2B

/* Interrupt Status Register */
#define STAT_DO      0x00
#define STAT_DI      0x01
#define STAT_CD      0x02
#define STAT_ST      0x03
#define STAT_MO      0x06
#define STAT_MI      0x07

#define STAT_MASK    0xF8

#define STAT_VGC     0x08
#define STAT_TC      0x10
#define STAT_PE      0x20
#define STAT_GE      0x40
#define STAT_INT     0x80

/* Bus ID Register */
#define BUSID_DID    0x07

/* Interrupt Register */
#define INTR_SEL     0x01
#define INTR_SELATN  0x02
#define INTR_RESEL   0x04
#define INTR_FC      0x08
#define INTR_BS      0x10
#define INTR_DC      0x20
#define INTR_ILL     0x40
#define INTR_RST     0x80

/*Sequence Step Register */
#define SEQ_0        0x00
#define SEQ_SELTIMEOUT 0x02
#define SEQ_CD       0x04

/*Configuration Register */
#define CFG1_RESREPT 0x40

#define CFG2_ENFEA   0x40

#define TCHI_FAS100A 0x04


/* ESP DMA control and status registers */

struct {
    Uint8 control;
    Uint8 status;
} esp_dma;

#define ESPCTRL_CLKMASK     0xc0    /* clock selection bits */
#define ESPCTRL_CLK10MHz    0x00
#define ESPCTRL_CLK12MHz    0x40
#define ESPCTRL_CLK16MHz    0xc0
#define ESPCTRL_CLK20MHz    0x80
#define ESPCTRL_ENABLE_INT  0x20    /* enable ESP interrupt */
#define ESPCTRL_MODE_DMA    0x10    /* select mode: 1 = dma, 0 = pio */
#define ESPCTRL_DMA_READ    0x08    /* select direction: 1 = scsi>mem, 0 = mem>scsi */
#define ESPCTRL_FLUSH       0x04    /* flush DMA buffer */
#define ESPCTRL_RESET       0x02    /* hard reset ESP */
#define ESPCTRL_CHIP_TYPE   0x01    /* select chip type: 1 = WD33C92, 0 = NCR53C90(A) */

#define ESPSTAT_STATE_MASK  0xc0
#define ESPSTAT_STATE_D0S0  0x00    /* DMA ready   for buffer 0, SCSI in buffer 0 */
#define ESPSTAT_STATE_D0S1  0x40    /* DMA request for buffer 0, SCSI in buffer 1 */
#define ESPSTAT_STATE_D1S1  0x80    /* DMA ready   for buffer 1, SCSI in buffer 1 */
#define ESPSTAT_STATE_D1S0  0xc0    /* DMA request for buffer 1, SCSI in buffer 0 */
#define ESPSTAT_OUTFIFO_MSK 0x38    /* output fifo byte (inverted) */
#define ESPSTAT_INFIFO_MSK  0x07    /* input fifo byte (inverted) */


void ESP_DMA_CTRL_Read(void);
void ESP_DMA_CTRL_Write(void);
void ESP_DMA_FIFO_STAT_Read(void);
void ESP_DMA_FIFO_STAT_Write(void);

void ESP_DMA_set_status(void);



void ESP_TransCountL_Read(void); 
void ESP_TransCountL_Write(void); 
void ESP_TransCountH_Read(void);
void ESP_TransCountH_Write(void); 
void ESP_FIFO_Read(void);
void ESP_FIFO_Write(void); 
void ESP_Command_Read(void); 
void ESP_Command_Write(void); 
void ESP_Status_Read(void);
void ESP_SelectBusID_Write(void); 
void ESP_IntStatus_Read(void);
void ESP_SelectTimeout_Write(void); 
void ESP_SeqStep_Read(void);
void ESP_SyncPeriod_Write(void); 
void ESP_FIFOflags_Read(void);
void ESP_SyncOffset_Write(void); 
void ESP_Configuration_Read(void); 
void ESP_Configuration_Write(void); 
void ESP_ClockConv_Write(void);
void ESP_Test_Write(void);

void ESP_Conf2_Read(void);

void esp_reset_hard(void);
void esp_reset_soft(void);
void esp_flush_fifo(void);
void handle_satn(void);
void handle_ti(void);
void esp_raise_irq(void);
void esp_lower_irq(void);
Uint32 get_cmd(void);
void do_cmd(void);
void do_busid_cmd(Uint8);
void esp_do_dma(void);
void esp_dma_done(void);
void esp_transfer_data(void);
void esp_command_complete(void);
void write_response(void);

extern Uint32 esp_counter;
