#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <maxmod9.h>

#include <nds.h>

#include "intro.h"
#include "select.h"
#include "controls.h"
#include "history.h"
#include "original.h"
#include "background.h"

#include "foul1.h"
#include "foul2.h"
#include "rsfoul.h"
#include "gameover.h"

#include "key1.h"
#include "key2.h"
#include "key3.h"
#include "key4.h"
#include "rskey.h"

#include "cage1.h"
#include "cage2.h"
#include "cage3.h"
#include "cage4.h"
#include "cage5.h"

#include "coco1.h"
#include "coco2.h"
#include "rscoco1.h"
#include "rscoco2.h"

#include "score0.h"
#include "score1.h"
#include "score2.h"
#include "score3.h"
#include "score4.h"
#include "score5.h"
#include "score6.h"
#include "score7.h"
#include "score8.h"
#include "score9.h"
#include "rsscore.h"

#include "bird1.h"
#include "bird2.h"
#include "bird3.h"
#include "bird4.h"

#include "rsbird1.h"
#include "rsbird2.h"
#include "rsbird3.h"
#include "rsbird4.h"

#include "croc1.h"
#include "croc2.h"
#include "croc3.h"
#include "croc4.h"
#include "croc5.h"

#include "rscroc1.h"
#include "rscroc2.h"
#include "rscroc3.h"
#include "rscroc4.h"
#include "rscroc5.h"

#include "junior1.h"
#include "junior2.h"
#include "junior3.h"
#include "junior4.h"
#include "junior8.h"
#include "junior10.h"
#include "junior12.h"
#include "junior13.h"
#include "junior15.h"
#include "junior18.h"
#include "junior19.h"
#include "junior20.h"
#include "rsjunior1.h"
#include "rsjunior2.h"
#include "rsjunior3.h"
#include "rsjunior4.h"
#include "rsjunior8.h"
#include "rsjunior10.h"
#include "rsjunior12.h"
#include "rsjunior13.h"
#include "rsjunior15.h"
#include "rsjunior18.h"
#include "rsjunior19.h"
#include "rsjunior20.h"

#include "jump1.h"
#include "jump2.h"
#include "jump3.h"
#include "jump4.h"
#include "jump5.h"
#include "rsjump1.h"
#include "rsjump2.h"
#include "rsjump3.h"
#include "rsjump4.h"
#include "rsjump5.h"

#include "soundbank.h"
#include "soundbank_bin.h"


struct pngimg { unsigned int *imageptr; int width; int height; }; 
struct enemy_status { bool visible; int precount; bool phase; int position; };


int foul_pos_map[3][2] = {
		{ 175, 28 },		/* position 1 */		/* [ ][1] : x-coordinate */
		{ 215, 28 },		/* position 2 */		/* [ ][2] : y-coordinate */
		{ 233, 28 }			/* position 3 */
	};
	
int key_pos_map[7][2] = {
		{ 80, 17 },		/* position 1 */		/* [ ][1] : x-coordinate */
		{ 80, 17 },		/* position 2 */		/* [ ][2] : y-coordinate */
		{ 80, 17 },		/* position 3 */
		{ 80, 17 },		/* position 4 */
		{ 80, 17 },		/* position 5 */
		{ 80, 17 },		/* position 6 */
		{ 80, 17 }		/* position 7 */
	};

int cage_pos_map[5][2] = {		
		{ 1, 8 },		/* position 1 */		/* [ ][1] : x-coordinate */
		{ 1, 8 },		/* position 2 */		/* [ ][2] : y-coordinate */
		{ 1, 8 },		/* position 3 */
		{ 1, 8 },		/* position 4 */
		{ 1, 8 }		/* position 5 */
	};
	
int coco_pos_map[4][2] = {
		{ 132, 50 },		/* position 1 */		/* [ ][1] : x-coordinate */
		{ 132, 86 },		/* position 2 */		/* [ ][2] : y-coordinate */
		{ 132, 128 },		/* position 3 */
		{ 132, 154 }		/* position 4 */
	};
	
int bird_pos_map[8][3] = { 
		{ 0, 4, 118 },			/* position 1 */		/* [ ][1] : position nr  */
		{ 1, 22, 135 },			/* position 2 */		/* [ ][2] : x-coordinate */
		{ 3, 58, 135 },			/* position 3 */		/* [ ][3] : y-coordinate */
		{ 5, 94, 139 },			/* position 4 */
		{ 7, 132, 136 },		/* position 5 */
		{ 9, 170, 137 },		/* position 6 */
		{ 11, 197, 136 },		/* position 7 */
		{ 13, 241, 127 }		/* position 8 */
	};	
	
int croc_pos_map[13][3] = {
		{ 22, 73, 106 },		/* position  1 */		/* [ ][1] : position nr  */
		{ 20, 90, 108 },		/* position  2 */		/* [ ][2] : x-coordinate */
		{ 18, 128, 107 },		/* position  3 */		/* [ ][3] : y-coordinate */
		{ 16, 168, 108 },		/* position  4 */
		{ 14, 200, 106 },		/* position  5 */
		{ 12, 238, 113 },		/* position  6 */
		{ 12, 234, 172 },		/* position  7 */
		{ 10, 200, 173 },		/* position  8 */
		{ 8, 168, 171 },		/* position  9 */
		{ 6, 130, 173 },		/* position 10 */
		{ 4, 90, 171 },			/* position 11 */
		{ 2, 54, 173 },			/* position 12 */
		{ 0, 19, 171 }			/* position 13 */
	};

int jr_pos_map[21][7] = {
		{ 0, 0, 0, 0, 0, 0, 0 },			/* not exists  */		/* [ ][0] : jump up      */
		{ 2, 3, 1, 1, 1, 33, 160 },		/* position  1 */		/* [ ][1] : move right   */
		{ 2, 4, 1, 2, 2, 33, 131 },		/* position  2 */       /* [ ][2] : move down    */
		{ 4, 5, 3, 1, 3, 60, 161 },		/* position  3 */		/* [ ][3] : move left    */
		{ 4, 4, 3, 4, 4, 65, 131 },		/* position  4 */		/* [ ][4] : move up      */
		{ 6, 7, 5, 3, 5, 100, 160 },		/* position  5 */		/* [ ][5] : x-coordinate */
		{ 6, 8, 5, 4, 6, 106, 131 },		/* position  6 */		/* [ ][6] : y-coordinate */
		{ 8, 9, 7, 5, 7, 144, 160 },		/* position  7 */
		{ 8, 10, 7, 6, 8, 143, 131 },		/* position  8 */
		{ 10, 11, 9, 7, 9, 180, 160 }, 	/* position  9 */
		{ 10, 10, 9, 10, 10, 179, 131 },	/* position 10 */
		{ 12, 11, 11, 9, 11, 212, 160 },	/* position 11 */
		{ 12, 12, 11, 10, 13, 213, 125},	/* position 12 */
		{ 13, 13, 12, 15, 13, 209, 96}, 	/* position 13 */
		{ 0, 0, 0, 0, 0, 0, 0 },			/* not exists  */
		{ 16, 13, 15, 17, 15, 176, 96},	/* position 15 */
		{ 16, 16, 15, 16, 16, 180, 72},	/* position 16 */
		{ 18, 15, 17, 19, 17, 144, 96},	/* position 17 */
		{ 18, 18, 17, 18, 18, 142, 54},	/* position 18 */
		{ 20, 17, 19, 1, 19, 107, 96},		/* position 19 */
		{ 20, 20, 19, 20, 20, 107, 72}		/* position 20 */
	};


int jump_pos_map[5][2] = {
		{ 80, 43 },			/* position 1 */		/* [ ][1] : x-coordinate */
		{ 58, 26 },			/* position 2 */		/* [ ][2] : y-coordinate */
		{ 58, 56 },			/* position 3 */
		{ 15, 110 },		/* position 4 */
		{ 4, 149 }			/* position 5 */
	};
	


struct enemy_status bird[4] = {
		{ FALSE, 0, 0, 0 },
		{ FALSE, 0, 0, 0 },
		{ FALSE, 0, 0, 0 },
		{ FALSE, 0, 0, 0 },
	};
	
struct enemy_status croc[6] = {
		{ FALSE, 0, 0 },
		{ FALSE, 0, 0 },
		{ FALSE, 0, 0 },
		{ FALSE, 0, 0 },
		{ FALSE, 0, 0 },
		{ FALSE, 0, 0 },
	};
	
	
pngimg img_foul1 = { (unsigned int *)foul1Bitmap, 36, 14 }; pngimg img_foul2 = { (unsigned int *)foul2Bitmap, 14, 14 };
pngimg img_gameover = { (unsigned int *)gameoverBitmap, 100, 45 }; pngimg img_rsfoul = { (unsigned int *)rsfoulBitmap, 72, 14 };
	
pngimg img_key1 = { (unsigned int *)key1Bitmap, 42, 14 }; pngimg img_key2 = { (unsigned int *)key2Bitmap, 42, 14 };
pngimg img_key3 = { (unsigned int *)key3Bitmap, 42, 14 }; pngimg img_key4 = { (unsigned int *)key4Bitmap, 42, 14 };
pngimg img_rskey = { (unsigned int *)rskeyBitmap, 42, 14 };
	
pngimg img_cage1 = { (unsigned int *)cage1Bitmap, 56, 46 }; pngimg img_cage2 = { (unsigned int *)cage2Bitmap, 56, 46 };
pngimg img_cage3 = { (unsigned int *)cage3Bitmap, 56, 46 }; pngimg img_cage4 = { (unsigned int *)cage4Bitmap, 56, 46 };
pngimg img_cage5 = { (unsigned int *)cage5Bitmap, 56, 46 };

pngimg img_coco1 = { (unsigned int *)coco1Bitmap, 6, 8 }; pngimg img_coco2 = { (unsigned int *)coco2Bitmap, 6, 18 };
pngimg img_rscoco1 = { (unsigned int *)rscoco1Bitmap, 6, 8 }; pngimg img_rscoco2 = { (unsigned int *)rscoco2Bitmap, 6, 18 };
	
pngimg img_score0 = { (unsigned int *)scoreBitmap, 16, 20 }; pngimg img_score1 = { (unsigned int *)score1Bitmap, 16, 20 };
pngimg img_score2 = { (unsigned int *)score2Bitmap, 16, 20 }; pngimg img_score3 = { (unsigned int *)score3Bitmap, 16, 20 };
pngimg img_score4 = { (unsigned int *)score4Bitmap, 16, 20 }; pngimg img_score5 = { (unsigned int *)score5Bitmap, 16, 20 };
pngimg img_score6 = { (unsigned int *)score6Bitmap, 16, 20 }; pngimg img_score7 = { (unsigned int *)score7Bitmap, 16, 20 };
pngimg img_score8 = { (unsigned int *)score8Bitmap, 16, 20 }; pngimg img_score9 = { (unsigned int *)score9Bitmap, 16, 20 };
pngimg img_rsscore = { (unsigned int *)rsscoreBitmap, 68, 20 };

pngimg img_bird1 = { (unsigned int *)bird1Bitmap, 8, 10 }; pngimg img_bird2 = { (unsigned int *)bird2Bitmap, 8, 10 };
pngimg img_bird3 = { (unsigned int *)bird3Bitmap, 10, 8 }; pngimg img_bird4 = { (unsigned int *)bird4Bitmap, 10, 10 };
pngimg img_rsbird1 = { (unsigned int *)rsbird1Bitmap, 8, 10 }; pngimg img_rsbird2 = { (unsigned int *)rsbird2Bitmap, 8, 10 };
pngimg img_rsbird3 = { (unsigned int *)rsbird3Bitmap, 10, 8 }; pngimg img_rsbird4 = { (unsigned int *)rsbird4Bitmap, 10, 10 };
	
pngimg img_croc1 = { (unsigned int *)croc1Bitmap, 8, 8 }; pngimg img_croc2 = { (unsigned int *)croc2Bitmap, 10, 10 };
pngimg img_croc3 = { (unsigned int *)croc3Bitmap, 6, 10 }; pngimg img_croc4 = { (unsigned int *)croc4Bitmap, 8, 8 };
pngimg img_croc5 = { (unsigned int *)croc5Bitmap, 10, 10 }; pngimg img_rscroc1 = { (unsigned int *)rscroc1Bitmap, 8, 8 };
pngimg img_rscroc2 = { (unsigned int *)rscroc2Bitmap, 10, 10 }; pngimg img_rscroc3 = { (unsigned int *)rscroc3Bitmap, 6, 10 };
pngimg img_rscroc4 = { (unsigned int *)rscroc4Bitmap, 8, 8 }; pngimg img_rscroc5 = { (unsigned int *)rscroc5Bitmap, 10, 10 };
	
pngimg img_junior1 = { (unsigned int *)junior1Bitmap, 20, 20 }; pngimg img_junior2 = { (unsigned int *)junior2Bitmap, 20, 20 };
pngimg img_junior3 = { (unsigned int *)junior3Bitmap, 22, 20 }; pngimg img_junior4 = { (unsigned int *)junior4Bitmap, 24, 20 };
pngimg img_junior8 = { (unsigned int *)junior8Bitmap, 18, 18 }; pngimg img_junior10 = { (unsigned int *)junior10Bitmap, 18, 20 };
pngimg img_junior12 = { (unsigned int *)junior12Bitmap, 20, 20 }; pngimg img_junior13 = { (unsigned int *)junior13Bitmap, 24, 20 };
pngimg img_junior15 = { (unsigned int *)junior15Bitmap, 24, 20 }; pngimg img_junior18 = { (unsigned int *)junior18Bitmap, 24, 20 };
pngimg img_junior19 = { (unsigned int *)junior19Bitmap, 22, 20 }; pngimg img_junior20 = { (unsigned int *)junior20Bitmap, 28, 18 };
pngimg img_rsjunior1 = { (unsigned int *)rsjunior1Bitmap, 20, 20 }; pngimg img_rsjunior2 = { (unsigned int *)rsjunior2Bitmap, 20, 20 };
pngimg img_rsjunior3 = { (unsigned int *)rsjunior3Bitmap, 22, 20 }; pngimg img_rsjunior4 = { (unsigned int *)rsjunior4Bitmap, 24, 20 };
pngimg img_rsjunior8 = { (unsigned int *)rsjunior8Bitmap, 18, 18 }; pngimg img_rsjunior10 = { (unsigned int *)rsjunior10Bitmap, 18, 20 };
pngimg img_rsjunior12 = { (unsigned int *)rsjunior12Bitmap, 20, 20 }; pngimg img_rsjunior13 = { (unsigned int *)rsjunior13Bitmap, 24, 20 };
pngimg img_rsjunior15 = { (unsigned int *)rsjunior15Bitmap, 24, 20 }; pngimg img_rsjunior18 = { (unsigned int *)rsjunior18Bitmap, 24, 20 };
pngimg img_rsjunior19 = { (unsigned int *)rsjunior19Bitmap, 22, 20 }; pngimg img_rsjunior20 = { (unsigned int *)rsjunior20Bitmap, 28, 18 };
	
pngimg img_jump1 = { (unsigned int *)jump1Bitmap, 18, 24 }; pngimg img_jump2 = { (unsigned int *)jump2Bitmap, 20, 20 };
pngimg img_jump3 = { (unsigned int *)jump3Bitmap, 24, 26 }; pngimg img_jump4 = { (unsigned int *)jump4Bitmap, 22, 20 };
pngimg img_jump5 = { (unsigned int *)jump5Bitmap, 14, 20 }; pngimg img_rsjump1 = { (unsigned int *)rsjump1Bitmap, 18, 24 };
pngimg img_rsjump2 = { (unsigned int *)rsjump2Bitmap, 20, 20 }; pngimg img_rsjump3 = { (unsigned int *)rsjump3Bitmap, 24, 26 };
pngimg img_rsjump4 = { (unsigned int *)rsjump4Bitmap, 22, 20 }; pngimg img_rsjump5 = { (unsigned int *)rsjump5Bitmap, 14, 20 };


int score;
int lives_counter;
bool double_score;

void sleepwait(int timer) {

	int frames;
	int counter;
	
	frames = ( timer * 58 ) / 1000000;
	
	for(counter=0; counter<frames; counter++) swiWaitForVBlank();

}


/* Select a low priority DMA channel to perform our background copying. */
static const int DMA_CHANNEL = 3;


void initVideo() {
    
    /*  Map VRAM to display a background on the main and sub screens. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG_0x06000000,
                        VRAM_B_MAIN_BG_0x06020000,
                        VRAM_C_SUB_BG_0x06200000,
                        VRAM_D_LCD);

    /*  Set the video mode on the main screen. */
    videoSetMode(MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE);

    /*  Set the video mode on the sub screen. */
    videoSetModeSub(MODE_5_2D | DISPLAY_BG3_ACTIVE); 
}


void initBackgrounds() {

    REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3); 
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;
    REG_BG3X = 0;
    REG_BG3Y = 0;

    REG_BG2CNT = BG_BMP16_128x128 | BG_BMP_BASE(8) | BG_PRIORITY(2);
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;

    REG_BG3CNT_SUB = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3);
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
}


void displayselect_bg() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     selectBitmap, 
                     (uint16 *)BG_BMP_RAM(0), 
                     selectBitmapLen); 
}


void displayintro_bg() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     introBitmap, 
                     (uint16 *)BG_BMP_RAM_SUB(0), 
                     introBitmapLen); 
}


void displaycontrols_bg() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     controlsBitmap, 
                     (uint16 *)BG_BMP_RAM_SUB(0), 
                     controlsBitmapLen); 
}


void displayhistory_bg() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     historyBitmap, 
                     (uint16 *)BG_BMP_RAM_SUB(0), 
                     historyBitmapLen); 
}


void displayoriginal_bg() {
	dmaCopyHalfWords(DMA_CHANNEL,
                     originalBitmap, 
                     (uint16 *)BG_BMP_RAM_SUB(0), 
                     originalBitmapLen); 
}


void displaygame_bg() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backgroundBitmap, 
                     (uint16 *)BG_BMP_RAM(0), 
                     backgroundBitmapLen); 
}



void display_jpeg(pngimg png, int x_pos, int y_pos) {
	
	uint16 			*pointer_scr;
	unsigned int 	*pointer_png; int width; int height;
	
	pointer_scr = (uint16 *)BG_BMP_RAM(0);
	
	pointer_png = png.imageptr;
	width 		= png.width;
	height 		= png.height;
	
	int i;

		for(i=0;i<=height/2-1;i++) {
		
			/* draw the even line */
			dmaCopyHalfWords(DMA_CHANNEL,
                     pointer_png+i*width, 
                     (uint16 *)pointer_scr+(y_pos+i*2)*256+x_pos, 
                     width*2);
		
			/* draw the uneven line */
			dmaCopyHalfWords(DMA_CHANNEL,
                     pointer_png+i*width+width/2, 
                     (uint16 *)pointer_scr+(y_pos+i*2+1)*256+x_pos, 
                     width*2);
		
		}
			
}


void display_jr(bool set_reset, int position) {
	
	/* reset junior image at given position */
	if( set_reset == FALSE) {
		
		switch ( position )
		{
			case 1: display_jpeg(img_rsjunior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 2: display_jpeg(img_rsjunior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 3: display_jpeg(img_rsjunior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 4: display_jpeg(img_rsjunior4, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 5: display_jpeg(img_rsjunior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 6: display_jpeg(img_rsjunior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 7: display_jpeg(img_rsjunior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 8: display_jpeg(img_rsjunior8, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 9: display_jpeg(img_rsjunior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 10: display_jpeg(img_rsjunior10, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 11: display_jpeg(img_rsjunior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 12: display_jpeg(img_rsjunior12, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 13: display_jpeg(img_rsjunior13, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 15: display_jpeg(img_rsjunior15, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 16: display_jpeg(img_rsjunior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 17: display_jpeg(img_rsjunior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 18: display_jpeg(img_rsjunior18, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 19: display_jpeg(img_rsjunior19, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 20: display_jpeg(img_rsjunior20, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
		}
	}
	
	/* set junior image at given position */
	if( set_reset == TRUE) {
		
		switch ( position )
		{
			case 1: display_jpeg(img_junior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 2: display_jpeg(img_junior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 3: display_jpeg(img_junior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 4: display_jpeg(img_junior4, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 5: display_jpeg(img_junior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 6: display_jpeg(img_junior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 7: display_jpeg(img_junior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 8: display_jpeg(img_junior8, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 9: display_jpeg(img_junior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 10: display_jpeg(img_junior10, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 11: display_jpeg(img_junior3, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 12: display_jpeg(img_junior12, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 13: display_jpeg(img_junior13, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 15: display_jpeg(img_junior15, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 16: display_jpeg(img_junior2, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 17: display_jpeg(img_junior1, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 18: display_jpeg(img_junior18, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 19: display_jpeg(img_junior19, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
			case 20: display_jpeg(img_junior20, jr_pos_map[position][5], jr_pos_map[position][6] ); break;
		}
	}


}



void display_score(int score) {

	int score_1, score_10, score_100, score_1000;

	/* play sound */
	mmEffect( SFX_SCORE );
	
	/* display units */
	score_1 = score % 10;
	switch ( score_1 )
		{
			case 0: display_jpeg(img_score0, 232, 7 ); break;
			case 1: display_jpeg(img_score1, 232, 7 ); break;
			case 2: display_jpeg(img_score2, 232, 7 ); break;
			case 3: display_jpeg(img_score3, 232, 7 ); break;
			case 4: display_jpeg(img_score4, 232, 7 ); break;
			case 5: display_jpeg(img_score5, 232, 7 ); break;
			case 6: display_jpeg(img_score6, 232, 7 ); break;
			case 7: display_jpeg(img_score7, 232, 7 ); break;
			case 8: display_jpeg(img_score8, 232, 7 ); break;
			case 9: display_jpeg(img_score9, 232, 7 ); break;	
		}
	
	/* display tens */
	if( score >= 10){
		score_10 = ( score / 10 ) % 10;
		switch ( score_10 )
		{
			case 0: display_jpeg(img_score0, 215, 7 ); break;
			case 1: display_jpeg(img_score1, 215, 7 ); break;
			case 2: display_jpeg(img_score2, 215, 7 ); break;
			case 3: display_jpeg(img_score3, 215, 7 ); break;
			case 4: display_jpeg(img_score4, 215, 7 ); break;
			case 5: display_jpeg(img_score5, 215, 7 ); break;
			case 6: display_jpeg(img_score6, 215, 7 ); break;
			case 7: display_jpeg(img_score7, 215, 7 ); break;
			case 8: display_jpeg(img_score8, 215, 7 ); break;
			case 9: display_jpeg(img_score9, 215, 7 ); break;	
		}
	}
	
	/* display hundreds */
	if( score >= 100){
		score_100 = ( score / 100 ) % 10;
		switch ( score_100 )
		{
			case 0: display_jpeg(img_score0, 198, 7 ); break;
			case 1: display_jpeg(img_score1, 198, 7 ); break;
			case 2: display_jpeg(img_score2, 198, 7 ); break;
			case 3: display_jpeg(img_score3, 198, 7 ); break;
			case 4: display_jpeg(img_score4, 198, 7 ); break;
			case 5: display_jpeg(img_score5, 198, 7 ); break;
			case 6: display_jpeg(img_score6, 198, 7 ); break;
			case 7: display_jpeg(img_score7, 198, 7 ); break;
			case 8: display_jpeg(img_score8, 198, 7 ); break;
			case 9: display_jpeg(img_score9, 198, 7 ); break;	
		}
	}
	
	/* display thousands */
	if( score >= 1000){
		score_1000 = ( score / 1000 ) % 10;
		switch ( score_1000 )
		{
			case 0: display_jpeg(img_score0, 181, 7 ); break;
			case 1: display_jpeg(img_score1, 181, 7 ); break;
			case 2: display_jpeg(img_score2, 181, 7 ); break;
			case 3: display_jpeg(img_score3, 181, 7 ); break;
			case 4: display_jpeg(img_score4, 181, 7 ); break;
			case 5: display_jpeg(img_score5, 181, 7 ); break;
			case 6: display_jpeg(img_score6, 181, 7 ); break;
			case 7: display_jpeg(img_score7, 181, 7 ); break;
			case 8: display_jpeg(img_score8, 181, 7 ); break;
			case 9: display_jpeg(img_score9, 181, 7 ); break;	
		}
	}
}


void update_score( int old_score, int new_score) {
	int score;
	int score_blink;
	
	/* increment score until new score and display intermediate scores */
	for( score = old_score+1; score <= new_score; score++) {
		display_score( score );
		
		/* check if score reaches 300 for chance mode */
		if(score == 300) {
	
			for(score_blink=0; score_blink<5; score_blink++) {
			
				sleepwait(300000); 
				display_jpeg(img_rsscore, 181, 7);
				sleepwait(300000);
				display_score( score ); 
			
			}
			
			/* still all lives left: enter double score mode */
			if( lives_counter == 3 ) {
			
				double_score = TRUE;

			}
			/* not all lives left: reset all misses */
			else {
			
				lives_counter = 3;
				display_jpeg(img_rsfoul, foul_pos_map[0][0], foul_pos_map[0][1] );
			
			}
			
		}
		
		sleepwait(100000);
	}
}


int main() {
	
	
	touchPosition touch;
	int selectscreen = 0;


    /* Turn on the 2D graphics core. */
    powerOn(POWER_ALL_2D);

    /* Configure the VRAM and background control registers. */
    lcdMainOnBottom(); 
    initVideo();
    initBackgrounds();
	

    /* Display the backgrounds. */
    displayselect_bg();
    displayintro_bg();
	
	/* initialize sound */
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	/* load sound effects */
	mmLoadEffect( SFX_COLLISION );
	mmLoadEffect( SFX_MOVEJUNIOR );
	mmLoadEffect( SFX_MOVEENEMY );
	mmLoadEffect( SFX_SCORE );
	mmLoadEffect( SFX_WRONGJUMP );
	
    for (;;) {

		touchRead(&touch);
		
		/* display control screen */
		if ( ( (touch.px>29) & (touch.px<112) ) & ( (touch.py>22) & (touch.py<85) ) & (selectscreen!=1) )
		{ 
			selectscreen = 1;
			displaycontrols_bg(); swiWaitForVBlank(); sleepwait(250000);
			mmEffect( SFX_MOVEJUNIOR );
		}
		
		/* display original screen */
		if ( ( (touch.px>29) & (touch.px<112) ) & ( (touch.py>109) & (touch.py<171) ) & (selectscreen!=2) ) 
		{ 
			selectscreen = 2;
			displayoriginal_bg(); swiWaitForVBlank(); sleepwait(250000);
			mmEffect( SFX_MOVEJUNIOR );
		}
		
		/* display history screen */
		if ( ( (touch.px>141) & (touch.px<225) ) & ( (touch.py>109) & (touch.py<171) ) & (selectscreen!=3) ) 
		{ 
			selectscreen =3;
			displayhistory_bg(); swiWaitForVBlank(); sleepwait(250000);
			mmEffect( SFX_MOVEJUNIOR );
		}
		
		/* play game */
		if ( ( (touch.px>141) & (touch.px<225) ) & ( (touch.py>22) & (touch.py<85) ) ) {
	
			displayintro_bg(); displaygame_bg();
			selectscreen = 4;
			
			int level = 1;
			score = 0;
			int old_score = 0;
			double_score = FALSE;
			
			lives_counter = 3;
			bool collision_detected = FALSE;
			
			int jr_position = 1;
			int jr_old_position = 1;
			bool special = FALSE;
			int special_counter = 0;

			int birds_active = 2;	/* initial number of birds */
			int bird_spacing = 4;	/* initial spacing between birds */
			int bird_index;
			int bird_index2;
			int bird_precount_max;
			int bird_old_position;
			
			int crocs_active = 2;	/* initial number of crocs */
			int croc_spacing = 8;	/* initial spacing between crocs */
			int croc_index;
			int croc_index2;
			int croc_precount_max;
			int croc_old_position;
			
			int key_position = 1;
			int coco_position = 1;
			bool coco_hit1 = FALSE;
			bool coco_hit2 = FALSE;
			bool coco_hit3 = FALSE;
			int cocohit_pause = 200000;
			
			bool enemy_moved = FALSE;
			
			int cage_index;
			
			int run_duration = 0;
			int run_durlow = 10;
			int run_durhigh = 30;
			int score_increment;
			
			bool hang_vine = FALSE;
			int hang_time = 0;
			int hang_max = 80;
			
			bool phase = 0; 
			
			int substep_counter = 0;
			int resolution = 5;
			long speed = 450000;
			int blink_counter;
			int blink_timer_hit = 500000;
			
			bool game_over = FALSE;
			
			u32 buttonsDown;
			
			
			/* setup initial birds */
			for( bird_index = 0; bird_index < birds_active; bird_index++) {
				bird_precount_max = 0;
				for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
					if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
				}
				bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
				bird[bird_index].visible = FALSE;
				bird[bird_index].position = 0;
				bird[bird_index].phase = 0;
			}
			
			for( bird_index = birds_active; bird_index <=3; bird_index++) {
				bird[bird_index].visible = FALSE;
				bird[bird_index].position = 0;
				bird[bird_index].phase = 0;
			}
			
			/* setup initial crocs */
			for( croc_index = 0; croc_index < crocs_active; croc_index++) {
				croc_precount_max = 0;
				for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
					if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
				}
				croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
				croc[croc_index].visible = FALSE;
				croc[croc_index].position = 0;
				croc[croc_index].phase = 0;
			}
			
			for( croc_index = crocs_active; croc_index <=5; croc_index++) {
				croc[croc_index].visible = FALSE;
				croc[croc_index].position = 0;
				croc[croc_index].phase = 0;
			}
			
			
			/* display initial junior, cage, coconut, key and score */
			display_jr(1, jr_position);
			
			cage_index = 1;
			display_jpeg(img_cage1, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] );
			
			display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
			
			display_jpeg(img_key1, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
			
			display_score( score );
			
			/* main game loop */
			while( !game_over ) {
				
				if( !special ) {
				
					jr_old_position = jr_position;
				
					/* read controller input */
					scanKeys(); 
					buttonsDown = keysDown();
				
					/* button up pressed */
					if (buttonsDown & KEY_UP) { jr_position = jr_pos_map[jr_position][4]; rand(); }
					
					/* button down pressed */
					if (buttonsDown & KEY_DOWN) { jr_position = jr_pos_map[jr_position][2]; rand(); }
					
					/* button right pressed */
					if (buttonsDown & KEY_RIGHT) { jr_position = jr_pos_map[jr_position][1]; rand(); }
					
					/* button left pressed */
					if ( (buttonsDown & KEY_LEFT) && !(buttonsDown & KEY_A) ){ jr_position = jr_pos_map[jr_position][3]; rand(); }
					
					/* button jump pressed */
					if( (buttonsDown & KEY_A) && !(buttonsDown & KEY_LEFT) ) { jr_position = jr_pos_map[jr_position][0]; rand(); }
					
					/* determine special action needed */
					switch ( jr_position )
					{
						case  4: special = TRUE; special_counter = 0; break;
						case 10: special = TRUE; special_counter = 0; break;
						case 18: special = TRUE; special_counter = 0; break;
						case 20: special = TRUE; special_counter = 0; break;
					}
					
					/* determine hang in vine */
					if( jr_position != jr_old_position) {
						
						switch( jr_position )
						{
							case  2: hang_vine = TRUE; hang_time = 0;
							case  6: hang_vine = TRUE; hang_time = 0;
							case  8: hang_vine = TRUE; hang_time = 0;
							case 12: hang_vine = TRUE; hang_time = 0;
							case 16: hang_vine = TRUE; hang_time = 0;
						}
					}
					
					/* handle drop from vine after maximum time */
					if( (hang_vine == TRUE) && (hang_time>=hang_max) ) {
						
						switch( jr_position )
						{
							case  2: jr_position = jr_pos_map[jr_position][2]; rand();
							case  6: jr_position = jr_pos_map[jr_position][2]; rand();
							case  8: jr_position = jr_pos_map[jr_position][2]; rand();
							case 12: jr_position = jr_pos_map[jr_position][2]; rand();
							case 16: jr_position = jr_pos_map[jr_position][2]; rand();
						}
						
						hang_vine = FALSE;
						hang_time = 0;
					} 
					
					if( hang_vine == TRUE) hang_time++;
					
					/* determine jump to key */
					if( (jr_position == 19) && (buttonsDown & KEY_LEFT) && (buttonsDown & KEY_A) ) { 
						
						/* correctly timed jump to key */
						if (key_position == 4) {
							
							/* show jump to key */
							display_jr(0, jr_position);
							display_jpeg(img_jump1, jump_pos_map[0][0], jump_pos_map[0][1] );
							sleepwait(700000);
							display_jpeg(img_rskey, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
							display_jpeg(img_rsjump1, jump_pos_map[0][0], jump_pos_map[0][1] );
							display_jpeg(img_jump2, jump_pos_map[1][0], jump_pos_map[1][1] );
							sleepwait(700000);
	
							/* determine score depending on run duration and cage part*/
							if(run_duration<=run_durlow) score_increment = 20;
							else {
								if(run_duration>=run_durhigh) score_increment = 5;
								else {
									score_increment = 5 + ( (run_durhigh-run_duration) / ((run_durhigh-run_durlow)/15) );
								}
							}
							if(cage_index == 4) score_increment+=20;
							run_duration = 0;
							
							/* blink part of the cage */
							for(blink_counter=0; blink_counter<3; blink_counter++) {
								
								/* remove part */
								switch( cage_index ) 
								{
									case 1: display_jpeg(img_cage2, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 2: display_jpeg(img_cage3, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 3: display_jpeg(img_cage4, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 4: display_jpeg(img_cage5, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
								}
								
								/* update score */
								if(score_increment >= 5) {
									old_score = score; score+=5; if(double_score) score+=5; update_score(old_score, score);
									score_increment-=5;
								}
								else {
									if(score_increment != 0) {
										old_score = score; score=score+score_increment; if(double_score) score=score+score_increment; update_score(old_score, score);
										sleepwait( (5-score_increment) * 100000);
										score_increment=0;
									}
								}
								
								/* restore part */
								switch( cage_index ) 
								{
									case 1: display_jpeg(img_cage1, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 2: display_jpeg(img_cage2, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 3: display_jpeg(img_cage3, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 4: display_jpeg(img_cage4, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
								}
								
								
								/* update score */
								if(score_increment >= 5) {
									old_score = score; score+=5; if(double_score) score+=5; update_score(old_score, score);
									score_increment-=5;
								}
								else {
									if(score_increment != 0) {
										old_score = score; score=score+score_increment; if(double_score) score=score+score_increment; update_score(old_score, score);
										sleepwait( (5-score_increment) * 100000);
										score_increment=0;
									}
								}
							}
							
							/* update remainder of score */
							if(score_increment > 0) {
								old_score = score; score=score+score_increment; if(double_score) score=score+score_increment; update_score(old_score, score);
								score_increment = 0;
							
							}
							
							switch( cage_index ) 
								{
									case 1: display_jpeg(img_cage2, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 2: display_jpeg(img_cage3, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 3: display_jpeg(img_cage4, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
									case 4: display_jpeg(img_cage1, cage_pos_map[cage_index-1][0], cage_pos_map[cage_index-1][1] ); break;
								}
							
							/* remove junior with key and jump down*/
							display_jpeg(img_rsjump2, jump_pos_map[1][0], jump_pos_map[1][1] );
							display_jpeg(img_jump3, jump_pos_map[2][0], jump_pos_map[2][1] );
							sleepwait(1000000);
							
							display_jpeg(img_rsjump3, jump_pos_map[2][0], jump_pos_map[2][1] );
							
							cage_index++;
							if( cage_index == 5) {
								cage_index = 1;
								level++;
								
								switch( level )
									{
										case 2: /* level 2: add an additional croc */
											crocs_active = 3;
											
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active-1; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
							
											croc[crocs_active-1].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[crocs_active-1].visible = FALSE;
											croc[crocs_active-1].position = 0;
											croc[crocs_active-1].phase = 0;
											
											break;
										
										case 3: /* level 3: add an additional bird */
											birds_active = 3;
											croc_spacing = 6;
											
											bird_precount_max = 0;
											for( bird_index2 = 0; bird_index2 < birds_active-1; bird_index2++) {
												if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
											}
							
											bird[birds_active-1].precount = bird_precount_max + rand() % bird_spacing + 3;
											bird[birds_active-1].visible = FALSE;
											bird[birds_active-1].position = 0;
											bird[birds_active-1].phase = 0;
											
											break;
											
										case 4: /* level 4: add an additional croc */
											crocs_active = 4;
											
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active-1; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
							
											croc[crocs_active-1].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[crocs_active-1].visible = FALSE;
											croc[crocs_active-1].position = 0;
											croc[crocs_active-1].phase = 0;
											
											break;
											
										case 5: /* level 5: add an additional croc */
											crocs_active = 5;
											croc_spacing = 5;
											
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active-1; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
							
											croc[crocs_active-1].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[crocs_active-1].visible = FALSE;
											croc[crocs_active-1].position = 0;
											croc[crocs_active-1].phase = 0;
											
											break;
											
										case 6:	/* level 6: add an additional bird */
											birds_active = 4;
											bird_spacing = 3;
											
											bird_precount_max = 0;
											for( bird_index2 = 0; bird_index2 < birds_active-1; bird_index2++) {
												if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
											}
							
											bird[birds_active-1].precount = bird_precount_max + rand() % bird_spacing + 3;
											bird[birds_active-1].visible = FALSE;
											bird[birds_active-1].position = 0;
											bird[birds_active-1].phase = 0;
											
											break;
											
										case 7: /* level 7: add an additional croc */
											crocs_active = 6;
											croc_spacing = 4;
											
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active-1; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
							
											croc[crocs_active-1].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[crocs_active-1].visible = FALSE;
											croc[crocs_active-1].position = 0;
											croc[crocs_active-1].phase = 0;
											
											break;
									
									}
							}
							
						}
						
						/* Badly timed jump to key */
						else {
							
							/* play sound */
							mmEffect( SFX_WRONGJUMP );
							
							display_jr(0, jr_position);
							display_jpeg(img_jump1, jump_pos_map[0][0], jump_pos_map[0][1] );
							sleepwait(700000);
							
							display_jpeg(img_rsjump1, jump_pos_map[0][0], jump_pos_map[0][1] );
							display_jpeg(img_jump4, jump_pos_map[3][0], jump_pos_map[3][1] );
							sleepwait(700000);
							
							display_jpeg(img_rsjump4, jump_pos_map[3][0], jump_pos_map[3][1] );
							display_jpeg(img_jump5, jump_pos_map[4][0], jump_pos_map[4][1] );

							sleepwait(700000);
							
							display_jpeg(img_rsjump5, jump_pos_map[4][0], jump_pos_map[4][1] );
							
							/* when in double score mode: disable it*/
							if(double_score) double_score = FALSE;
							
							/* increase fouls */
							lives_counter--;
							if (lives_counter == 2) display_jpeg(img_foul1, foul_pos_map[0][0], foul_pos_map[0][1] );
							if (lives_counter == 1) display_jpeg(img_foul2, foul_pos_map[1][0], foul_pos_map[1][1] );
							
							if( lives_counter == 0) {
								display_jpeg(img_foul2, foul_pos_map[2][0], foul_pos_map[2][1] );
								
								display_jpeg(img_gameover, 80, 71);
								
								/* wait for buttonpress */
								do { 
									sleepwait(100000);
									
									touchRead(&touch);
		
									if ( ( (touch.px>80) & (touch.px<180) ) & ( (touch.py>71) & (touch.py<116) ) ) break;
								
								} while ( 1 );	
					
								game_over = TRUE;
							}
							
						}
						
						/* reset junior to position 1 */
						display_jr(0, jr_position);
						jr_position = 1; jr_old_position = 1;
						display_jr(1, jr_position);
						
						
						/* reset crocs in positions 10, 11, 12 and 13 */
						for( croc_index = 0; croc_index < crocs_active; croc_index++) {
							if( croc[croc_index].position >= 9 ) {
							
								switch( croc[croc_index].position )
								{
									case 10:
									case 12: display_jpeg(img_rscroc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
									case 9:
									case 11: display_jpeg(img_rscroc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
								}
							
								croc_precount_max = 0;
								for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
									if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
								}
							
								croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
								croc[croc_index].visible = FALSE;
								croc[croc_index].position = 0;
								croc[croc_index].phase = 0;
							}	
						}
						
						/* reset birds in positions 0 and 1 */
						for( bird_index = 0; bird_index < birds_active; bird_index++) {
							if( bird[bird_index].position <= 1 ) {
							
								switch( bird[bird_index].position )
								{
									case 0: display_jpeg(img_rsbird1, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
									case 1: display_jpeg(img_rsbird2, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
								}
							
								bird_precount_max = 0;
								for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
									if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
								}
							
								bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
								bird[bird_index].visible = FALSE;
								bird[bird_index].position = 0;
								bird[bird_index].phase = 0;
							}	
						}
						
						/* reset coconut */
						coco_position = 1;
						coco_hit1 = FALSE;
						coco_hit2 = FALSE;
						coco_hit3 = FALSE;
						display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
						
						/* reset run duration */
						run_duration = 0;
						
						collision_detected = FALSE;
						special = FALSE;
						special_counter = 0;
						substep_counter = 0;
						
						/* re-enter the while loop and continue game */
						continue;
					}
					
					/* determine jump into the bushes */
					if( (jr_position == 1) && (jr_old_position == 19) ) { 

						/* play sound */
						mmEffect( SFX_WRONGJUMP );

						display_jr(0, jr_old_position);
						display_jpeg(img_jump4, jump_pos_map[3][0], jump_pos_map[3][1] );
						sleepwait(1400000);
						
						display_jpeg(img_rsjump4, jump_pos_map[3][0], jump_pos_map[3][1] );
						display_jpeg(img_jump5, jump_pos_map[4][0], jump_pos_map[4][1] );

						sleepwait(700000);
			
						display_jpeg(img_rsjump5, jump_pos_map[4][0], jump_pos_map[4][1] );

						/* when in double score mode: disable it*/
						if(double_score) double_score = FALSE;

						/* increase fouls */
						lives_counter--;
						if (lives_counter == 2) display_jpeg(img_foul1, foul_pos_map[0][0], foul_pos_map[0][1] );
						if (lives_counter == 1) display_jpeg(img_foul2, foul_pos_map[1][0], foul_pos_map[1][1] );
							
						if( lives_counter == 0) {
							display_jpeg(img_foul2, foul_pos_map[2][0], foul_pos_map[2][1] );
						
							display_jpeg(img_gameover, 80, 71);
							
							/* wait for buttonpress */
							do { 
								sleepwait(100000);
		
								touchRead(&touch);
		
								if ( ( (touch.px>80) & (touch.px<180) ) & ( (touch.py>71) & (touch.py<116) ) ) break;
							
							} while ( 1 );	
				
							game_over = TRUE;
						}
					
						/* reset junior to position 1 */
						display_jr(0, jr_old_position);
						jr_position = 1; jr_old_position = 1;
						display_jr(1, jr_position);
						
						
						/* reset crocs in positions 10, 11, 12 and 13 */
						for( croc_index = 0; croc_index < crocs_active; croc_index++) {
							if( croc[croc_index].position >= 9 ) {
							
								switch( croc[croc_index].position )
								{
									case 10:
									case 12: display_jpeg(img_rscroc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
									case 9:
									case 11: display_jpeg(img_rscroc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
								}
								
								croc_precount_max = 0;
								for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
									if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
								}
								croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
								croc[croc_index].visible = FALSE;
								croc[croc_index].position = 0;
								croc[croc_index].phase = 0;
							}	
						}
						
						/* reset birds in positions 0 and 1 */
						for( bird_index = 0; bird_index < birds_active; bird_index++) {
							if( bird[bird_index].position <= 1 ) {
							
								switch( bird[bird_index].position )
								{
									case 0: display_jpeg(img_rsbird1, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
									case 1: display_jpeg(img_rsbird2, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
								}
							
								bird_precount_max = 0;
								for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
									if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
								}
							
								bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
								bird[bird_index].visible = FALSE;
								bird[bird_index].position = 0;
								bird[bird_index].phase = 0;
							}	
						}
						
						/* reset coconut */
						coco_position = 1;
						coco_hit1 = FALSE;
						coco_hit2 = FALSE;
						coco_hit3 = FALSE;
						display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
						
						/* reset run duration */
						run_duration = 0;
						
						collision_detected = FALSE;
						special = FALSE;
						special_counter = 0;
						substep_counter = 0;
						
						/* re-enter the while loop and continue game */
						continue;
					}
					
					/* detect collision with birds */
					for( bird_index = 0; bird_index < birds_active; bird_index++) {
						if ( bird[bird_index].visible == TRUE) {
						
							if ( jr_old_position < jr_position) {
								if ( (jr_old_position < bird_pos_map[bird[bird_index].position][0]) && (jr_position > bird_pos_map[bird[bird_index].position][0]) ) {
									collision_detected = TRUE;
								}
							}
							else {
								if ( (jr_old_position > bird_pos_map[bird[bird_index].position][0]) && (jr_position < bird_pos_map[bird[bird_index].position][0]) ) {
									collision_detected = TRUE;
								}
							}
						}
					}
					
					/* detect collision with crocs */
					for( croc_index = 0; croc_index < crocs_active; croc_index++) {
						if ( croc[croc_index].visible == TRUE) {
						
							if ( jr_old_position < jr_position) {
								if ( (jr_old_position < croc_pos_map[croc[croc_index].position][0]) && (jr_position > croc_pos_map[croc[croc_index].position][0]) ) {
									collision_detected = TRUE;
								}
							}
							else {
								if ( (jr_old_position > croc_pos_map[croc[croc_index].position][0]) && (jr_position < croc_pos_map[croc[croc_index].position][0]) ) {
									collision_detected = TRUE;
								}
							}
						}
					}
					
					/* handle collision */
					if( collision_detected == TRUE ) {
					
						/* play sound */
						mmEffect( SFX_COLLISION );
					
						/* blink jr */
						for(blink_counter=0; blink_counter<3; blink_counter++) {
								display_jr(0, jr_old_position);

								sleepwait( 210000 );
								
								display_jr(1, jr_old_position);
								
								sleepwait( blink_timer_hit );
							}
						
						/* when in double score mode: disable it*/
						if(double_score) double_score = FALSE;
	
						/* increase fouls */
						lives_counter--;
						if (lives_counter == 2) display_jpeg(img_foul1, foul_pos_map[0][0], foul_pos_map[0][1] );
						if (lives_counter == 1) display_jpeg(img_foul2, foul_pos_map[1][0], foul_pos_map[1][1] );
							
						if( lives_counter == 0) {
							display_jpeg(img_foul2, foul_pos_map[2][0], foul_pos_map[2][1] );
						
							display_jpeg(img_gameover, 80, 71);
							
							/* wait for buttonpress */
							do { 
								sleepwait(100000);
		
								touchRead(&touch);
		
								if ( ( (touch.px>80) & (touch.px<180) ) & ( (touch.py>71) & (touch.py<116) ) ) break;
							
							} while ( 1 );	
				
							game_over = TRUE;
						}
					
						/* reset junior to position 1 */
						display_jr(0, jr_old_position);
						jr_position = 1; jr_old_position = 1;
						display_jr(1, jr_position);
						
						
						/* reset crocs in positions 10, 11, 12 and 13 */
						for( croc_index = 0; croc_index < crocs_active; croc_index++) {
							if( croc[croc_index].position >= 9 ) {
							
								switch( croc[croc_index].position )
								{
									case 10:
									case 12: display_jpeg(img_rscroc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
									case 9:
									case 11: display_jpeg(img_rscroc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
								}								
								
								croc_precount_max = 0;
								for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
									if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
								}
								croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
								croc[croc_index].visible = FALSE;
								croc[croc_index].position = 0;
								croc[croc_index].phase = 0;
							}	
						}
						
						/* reset birds in positions 0 and 1 */
						for( bird_index = 0; bird_index < birds_active; bird_index++) {
							if( bird[bird_index].position <= 1 ) {
							
								switch( bird[bird_index].position )
								{
									case 0: display_jpeg(img_rsbird1, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
									case 1: display_jpeg(img_rsbird2, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
								}
							
								bird_precount_max = 0;
								for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
									if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
								}
							
								bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
								bird[bird_index].visible = FALSE;
								bird[bird_index].position = 0;
								bird[bird_index].phase = 0;
							}	
						}
						
						/* reset coconut */
						coco_position = 1;
						coco_hit1 = FALSE;
						coco_hit2 = FALSE;
						coco_hit3 = FALSE;
						display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
						
						/* reset run duration */
						run_duration = 0;
						
						collision_detected = FALSE;
						special = FALSE;
						special_counter = 0;
						substep_counter = 0;
						
						/* re-enter the while loop and continue game */
						continue;
					}
					
				}	
				
				else {
					
					jr_old_position = jr_position;
					
					/* handle special action */
					switch ( jr_position )
					{
						/* position 4: float in the air and fall again */
						case 4 :
							if ( special_counter < 2 * resolution ) {
								special_counter++;
							}
							else {
								display_jr(0, jr_position);
								special = FALSE; jr_position = 3;
								display_jr(1, jr_position);
							}
							break;
						
						/* position 10: float in the air and fall again */
						case 10 :
							if ( special_counter < 2 * resolution ) {
								special_counter++;
							}
							else {
								display_jr(0, jr_position);
								special = FALSE; jr_position = 9;
								display_jr(1, jr_position);
							}
							break;
						
						/* position 18: drop coconut if existent else float in the air and fall again */
						case 18 :
							if ( special_counter <= 2 * resolution + 3 ) {
								
								/* drop coconut phase 1 */
								if ( ( coco_position == 1 ) && (special_counter == 0 ) ) {
									display_jpeg(img_rscoco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
									coco_position++;
									display_jpeg(img_coco2, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);	
								}
								
								/* determine coconut hit croc upper level */
								if ( ( coco_position == 2 ) && (special_counter < resolution ) && (coco_hit1 == FALSE)) {
									for( croc_index = 0; croc_index < crocs_active; croc_index++) {
										if ( croc_pos_map[croc[croc_index].position][0] == 18 ) {
																	
											coco_hit1 = TRUE;

											sleepwait( cocohit_pause );
											
											/* update score */
											old_score = score; score+=3; if(double_score) score+=3; update_score(old_score, score);
											
											/* reset hit croc */
											display_jpeg(img_rscroc2, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
											croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[croc_index].visible = FALSE;
											croc[croc_index].position = 0;
											croc[croc_index].phase = 0;			
										}
									}
								}
								
								/* drop coconut phase 2 */
								if ( ( coco_position == 2 ) && (special_counter == resolution ) ) {
									display_jpeg(img_rscoco2, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
									coco_position++;
									display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);	
								}
								
								/* determine coconut hit bird */
								if ( ( coco_position == 3 ) && (special_counter < 2* resolution ) && (coco_hit2 == FALSE)) {
									for( bird_index = 0; bird_index < birds_active; bird_index++) {
										if ( bird_pos_map[bird[bird_index].position][0] == 7 ) {
											
											coco_hit2 = TRUE;

											sleepwait( cocohit_pause );
											
											/* update score */
											old_score = score; score+=6; if(double_score) score+=6; update_score(old_score, score);
											
											/* reset hit bird */
											display_jpeg(img_rsbird3, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );
											bird_precount_max = 0;
											for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
												if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
											}
											bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
											bird[bird_index].visible = FALSE;
											bird[bird_index].position = 0;
											bird[bird_index].phase = 0;		
										}
									}
								}	
								
								/* drop coconut phase 3 */
								if ( ( coco_position == 3 ) && (special_counter == 2 * resolution ) ) {
									display_jpeg(img_rscoco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
									coco_position++;
									display_jpeg(img_coco2, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);	
								}
								
								/* determine coconut hit croc lower level */
								if ( ( coco_position == 4 ) && (special_counter < 2* resolution + 3 ) && (coco_hit3 == FALSE)) {
									for( croc_index = 0; croc_index < crocs_active; croc_index++) {
										if ( croc_pos_map[croc[croc_index].position][0] == 6 ) {
											
											coco_hit3 = TRUE;

											sleepwait( cocohit_pause );

											/* update score */
											old_score = score; score+=9; if(double_score) score+=9; update_score(old_score, score);
											
											/* reset hit croc */
											display_jpeg(img_rscroc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
											croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
											croc[croc_index].visible = FALSE;
											croc[croc_index].position = 0;
											croc[croc_index].phase = 0;		
										}
									}
								}
								
								/* drop coconut phase 4: reset coconut */
								if ( ( coco_position == 4 ) && (special_counter == 2 * resolution + 3 ) ) {
									display_jpeg(img_rscoco2, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
									coco_position = 5;
								}
								
								special_counter++;
							}
							else {
								display_jr(0, jr_position);
								special = FALSE; jr_position = 17;
								display_jr(1, jr_position);
							}
							break;
							
						/* position 20: float in the air and fall again */
						case 20 :
							if ( special_counter < 2 * resolution ) {
								special_counter++;
							}
							else {
								display_jr(0, jr_position);
								special = FALSE; jr_position = 19;
								display_jr(1, jr_position);
							}
							break;
					}	
				}
				
				
				/* redraw junior */
				if ( jr_position != jr_old_position ) {
					display_jr(0, jr_old_position);
					display_jr(1, jr_position);
					
					/* play sound */
					mmEffect( SFX_MOVEJUNIOR );
				}
				
				/* control speed */
				sleepwait( speed / resolution );
				
				substep_counter++;
				
				
				if ( substep_counter == resolution ) {
				
					enemy_moved = FALSE;
					run_duration++;
					
					/* move birds */
					for( bird_index = 0; bird_index < birds_active; bird_index++) {
						
						/* move invisible birds in pre queue */
						if ( bird[bird_index].precount > 1 ) {
							bird[bird_index].precount--;
						}
						else {
							
							/* display bird if it leaves the pre queue */
							if ( bird[bird_index].precount == 1) {
								bird[bird_index].precount--;
								bird[bird_index].visible = TRUE;
								bird[bird_index].phase = phase;
								bird[bird_index].position = 0;
								display_jpeg(img_bird1, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );
							}
							else {
						
								/* move visible bird */
								if( bird[bird_index].phase == phase) {				
									
									if( enemy_moved == FALSE) {
										enemy_moved = TRUE;
										
										/* play sound */
										mmEffect( SFX_MOVEENEMY );
									
									}
									
									bird_old_position = bird[bird_index].position;
									bird[bird_index].position++; 
							
									/* detect collision */
									if( (bird[bird_index].position != 8) && (jr_position < bird_pos_map[bird[bird_index].position][0]) && (jr_position > bird_pos_map[bird[bird_index].position-1][0]) ) {
										collision_detected = TRUE;
										bird[bird_index].position = bird_old_position;
									}
									
									else {
							
										/* place bird back in pre queue */
										if( bird[bird_index].position == 8 ) {
											display_jpeg(img_rsbird4, bird_pos_map[bird_old_position][1], bird_pos_map[bird_old_position][2] );
											bird[bird_index].visible = FALSE;
											bird_precount_max = 0;
											for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
												if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
											}
											bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
										}
										
										/* display bird in new position */
										else {
											switch( bird[bird_index].position )
											{	
												case 1:
													display_jpeg(img_rsbird1, bird_pos_map[bird_old_position][1], bird_pos_map[bird_old_position][2] );
													display_jpeg(img_bird2, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );											
													break;
													
												case 2:
													display_jpeg(img_rsbird2, bird_pos_map[bird_old_position][1], bird_pos_map[bird_old_position][2] );
													display_jpeg(img_bird3, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );											
													break;
												
												case 4:
												case 6:
													display_jpeg(img_rsbird4, bird_pos_map[bird_old_position][1], bird_pos_map[bird_old_position][2] );
													display_jpeg(img_bird3, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );											
													break;
												
												case 3:
												case 5:
												case 7:
													display_jpeg(img_rsbird3, bird_pos_map[bird_old_position][1], bird_pos_map[bird_old_position][2] );
													display_jpeg(img_bird4, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] );											
													break;
											}	
										}
									}
								}
							}
						}
					}
				
					/* move crocs */
					for( croc_index = 0; croc_index < crocs_active; croc_index++) {
						
						/* move invisible crocs in pre queue */
						if ( croc[croc_index].precount > 1 ) {
							croc[croc_index].precount--;
						}
						else {
							
							/* display croc if it leaves the pre queue */
							if ( croc[croc_index].precount == 1) {
								croc[croc_index].precount--;
								croc[croc_index].visible = TRUE;
								croc[croc_index].phase = phase;
								croc[croc_index].position = 0;
								display_jpeg(img_croc2, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );
							}
							
							else {
						
								/* move visible croc */
								if( croc[croc_index].phase == phase) {				
									
									if( enemy_moved == FALSE) {
										enemy_moved = TRUE;
										
										/* play sound */
										mmEffect( SFX_MOVEENEMY );
									
									}
									
									croc_old_position = croc[croc_index].position;
									croc[croc_index].position++; 
							
									/* detect collision */
									if( (croc[croc_index].position != 13) && (jr_position > croc_pos_map[croc[croc_index].position][0]) && (jr_position < croc_pos_map[croc[croc_index].position-1][0]) ) {
										collision_detected = TRUE;
										croc[croc_index].position = croc_old_position;
									}
							
									else {
									
										/* increase score if junior jumped over croc */
										if( (croc_pos_map[croc[croc_index].position][0] == 2 ) && ( jr_position == 4 ) ) {
											old_score = score; score++; if(double_score) score++; update_score(old_score, score);
										} 
										if( (croc_pos_map[croc[croc_index].position][0] == 8 ) && ( jr_position == 10 ) ) {
											old_score = score; score++; if(double_score) score++; update_score(old_score, score);
										}
										if( (croc_pos_map[croc[croc_index].position][0] == 16 ) && ( jr_position == 18 ) ) {
											old_score = score; score++; if(double_score) score++; update_score(old_score, score);
										}
										if( (croc_pos_map[croc[croc_index].position][0] == 18 ) && ( jr_position == 20 ) ) {
											old_score = score; score++; if(double_score) score++; update_score(old_score, score);
										}
									
										/* place croc back in pre queue */
										if( croc[croc_index].position == 13 ) {
											display_jpeg(img_rscroc5, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
											croc[croc_index].visible = FALSE;
											croc_precount_max = 0;
											for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
												if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
											}
											croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
										}
										
										/* display croc in new position */
										else {
											switch( croc[croc_index].position )
											{	
												case 1:
												case 3:
													display_jpeg(img_rscroc2, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc1, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
													
												case 2:
												case 4:
													display_jpeg(img_rscroc1, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc2, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
													
												case 5:
													display_jpeg(img_rscroc2, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc3, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
													
												case 6:
													display_jpeg(img_rscroc3, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
													
												case 7:
												case 9:
												case 11:
													display_jpeg(img_rscroc5, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
													
												case 8:
												case 10:
												case 12:
													display_jpeg(img_rscroc4, croc_pos_map[croc_old_position][1], croc_pos_map[croc_old_position][2] );
													display_jpeg(img_croc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] );											
													break;
											}
										}
									}
								}
							}
						}
					}
					
					/* handle collision */
					if( collision_detected == TRUE ) {
					
						/* play sound */
						mmEffect( SFX_COLLISION );
					
						/* blink jr */
						for(blink_counter=0; blink_counter<3; blink_counter++) {
								display_jr(0, jr_position);

								sleepwait( 210000 );
								
								display_jr(1, jr_position);
								
								sleepwait( blink_timer_hit );
							}	

						/* when in double score mode: disable it*/
							if(double_score) double_score = FALSE;						
						
						/* increase fouls */
						lives_counter--;
						if (lives_counter == 2) display_jpeg(img_foul1, foul_pos_map[0][0], foul_pos_map[0][1] );
						if (lives_counter == 1) display_jpeg(img_foul2, foul_pos_map[1][0], foul_pos_map[1][1] );
							
						if( lives_counter == 0) {
							display_jpeg(img_foul2, foul_pos_map[2][0], foul_pos_map[2][1] );
								
							display_jpeg(img_gameover, 80, 71);
								
							/* wait for buttonpress */
							do { 
								sleepwait(100000);
		
								touchRead(&touch);
		
								if ( ( (touch.px>80) & (touch.px<180) ) & ( (touch.py>71) & (touch.py<116) ) ) break;
							
							} while ( 1 );	
				
							game_over = TRUE;
						}
					
						/* reset junior to position 1 */
						display_jr(0, jr_position);
						jr_position = 1; jr_old_position = 1;
						display_jr(1, jr_position);
						
						
						/* reset crocs in positions 10, 11, 12 and 13 */
						for( croc_index = 0; croc_index < crocs_active; croc_index++) {
							if( croc[croc_index].position >= 9 ) {
							
								switch( croc[croc_index].position )
								{
									case 10:
									case 12: display_jpeg(img_rscroc5, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
									case 9:
									case 11: display_jpeg(img_rscroc4, croc_pos_map[croc[croc_index].position][1], croc_pos_map[croc[croc_index].position][2] ); break;
								}
								
								croc_precount_max = 0;
								for( croc_index2 = 0; croc_index2 < crocs_active; croc_index2++) {
									if(croc[croc_index2].precount > croc_precount_max) croc_precount_max = croc[croc_index2].precount;
								}
								croc[croc_index].precount = croc_precount_max + rand() % croc_spacing + 3;
								croc[croc_index].visible = FALSE;
								croc[croc_index].position = 0;
								croc[croc_index].phase = 0;
							}	
						}
						
						/* reset birds in positions 0 and 1 */
						for( bird_index = 0; bird_index < birds_active; bird_index++) {
							if( bird[bird_index].position <= 1 ) {
							
								switch( bird[bird_index].position )
								{
									case 0: display_jpeg(img_rsbird1, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
									case 1: display_jpeg(img_rsbird2, bird_pos_map[bird[bird_index].position][1], bird_pos_map[bird[bird_index].position][2] ); break;
								}
							
								bird_precount_max = 0;
								for( bird_index2 = 0; bird_index2 < birds_active; bird_index2++) {
									if(bird[bird_index2].precount > bird_precount_max) bird_precount_max = bird[bird_index2].precount;
								}
							
								bird[bird_index].precount = bird_precount_max + rand() % bird_spacing + 3;
								bird[bird_index].visible = FALSE;
								bird[bird_index].position = 0;
								bird[bird_index].phase = 0;
							}	
						}
						
						/* reset coconut */
						coco_position = 1;
						coco_hit1 = FALSE;
						coco_hit2 = FALSE;
						coco_hit3 = FALSE;
						display_jpeg(img_coco1, coco_pos_map[coco_position-1][0], coco_pos_map[coco_position-1][1]);
						
						/* reset run duration */
						run_duration = 0;
						
						collision_detected = FALSE;
						special = FALSE;
						special_counter = 0;
						substep_counter = 0;
						
						/* re-enter the while loop and continue game */
						continue;
					}
					
				
					/* move key */	
					key_position++;
					if (key_position == 8) key_position = 1;
					
					if ( (key_position == 1) || (key_position == 7) ) display_jpeg(img_key1, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
					if ( (key_position == 2) || (key_position == 6) ) display_jpeg(img_key2, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
					if ( (key_position == 3) || (key_position == 5) ) display_jpeg(img_key3, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
					if (key_position == 4) display_jpeg(img_key4, key_pos_map[key_position-1][0], key_pos_map[key_position-1][1]);
					
					/* toggle phase */
					phase = !phase;
					substep_counter = 0;
					
				}
				
			}
			
			displayselect_bg();
		
		}
	
	}

    return 0;
}
