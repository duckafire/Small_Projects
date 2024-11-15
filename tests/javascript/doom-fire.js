// BASED IN:
//https://github.com/filipedeschamps/doom-fire-algorithm

let DOOM_FIRE_RENDER = null;
let DOOM_FIRE_CELLS = null;
const DOOM_FIRE_CELL_DIM = "3vw";
const DOOM_FIRE_LOOP_INTERVAL = 50;
const DOOM_FIRE_WIDTH = 33;
const DOOM_FIRE_HEIGHT = 33;
const DOOM_FIRE_DIM = DOOM_FIRE_WIDTH * DOOM_FIRE_HEIGHT;
const DOOM_FIRE_INTENSITY = [];
const DOOM_FIRE_LAST_COLOR_ID = 20; // x21 colors
const DOOM_FIRE_PALETTE = [[7,7,7],[47,15,7],[87,23,7],[119,31,7],[159,47,7],[191,71,7],[223,79,7],[223,87,7],[215,95,7],[207,111,15],[207,127,15],[199,135,23],[199,151,31],[191,159,31],[191,167,39],[191,175,47],[183,183,47],[183,183,55],[207,207,111],[223,223,159],[239,239,199],[255,255,255]];

/* ORIGINAL
const DOOM_FIRE_PALETTE = [[7,7,7],[31,7,7],[47,15,7],[71,15,7],[87,23,7],[103,31,7],[119,31,7],[143,39,7],[159,47,7],[175,63,7],[191,71,7],[199,71,7],[223,79,7],[223,87,7],[223,87,7],[215,95,7],[215,95,7],[215,103,15],[207,111,15],[207,119,15],[207,127,15],[207,135,23],[199,135,23],[199,143,23],[199,151,31],[191,159,31],[191,159,31],[191,167,39],[191,167,39],[191,175,47],[183,175,47],[183,183,47],[183,183,55],[207,207,111],[223,223,159],[239,239,199],[255,255,255]];
*/

function main(tableParentId, tableTop, tableLeft){
	init(tableParentId, tableTop, tableLeft);
	setInterval(update, DOOM_FIRE_LOOP_INTERVAL);
}

function init(tableParentId, tableTop, tableLeft){
	// create table to render effect
	const table = document.createElement("table");
	table.id = "doom-fire-render";

	let html = "";

	for(let row = 0; row < DOOM_FIRE_HEIGHT; row++){
		html += "<tr>";
		for(let column = 0; column < DOOM_FIRE_WIDTH; column++){
			html += "<td class=\"doom-fire-cell\"></td>";
			DOOM_FIRE_INTENSITY[column + (row * DOOM_FIRE_WIDTH)] = 0;
		}

		html += "</tr>";
	}

	table.innerHTML = html;
	table.style.padding = "0px";
	table.style.margin = "0px";
	table.style.border = "1px solid #000";
	table.style.borderCollapse = "collapse";
	DOOM_FIRE_RENDER = table;

	if(tableTop != undefined)
		table.style.top = tableTop;

	if(tableLeft != undefined)
		table.style.left = tableTop;

	if(tableParentId == undefined)
		document.body.appendChild(table);
	else
		document.getElementById(tableParentId).appendChild(table);

	// set style to table items: <td></td>
	const cells = document.querySelectorAll(".doom-fire-cell");
	
	cells.forEach(it => {
		it.rgbId = 0;
		it.rgbUp = () => {
			let r = DOOM_FIRE_PALETTE[ it.rgbId ][0];
			let g = DOOM_FIRE_PALETTE[ it.rgbId ][1];
			let b = DOOM_FIRE_PALETTE[ it.rgbId ][2];

			it.style.background = `rgb(${r},${g},${b})`;
		}

		//it.style.border = "1px solid #000";
		it.style.width = DOOM_FIRE_CELL_DIM;
		it.style.height = DOOM_FIRE_CELL_DIM;
	});

	DOOM_FIRE_CELLS = cells;

	// set color initial color
	let id;
	for(let row = 0; row < DOOM_FIRE_HEIGHT; row++){
		for(let column = 0; column < DOOM_FIRE_WIDTH; column++){
			id = column + (row * DOOM_FIRE_WIDTH);

			cells[id].rgbId = ((row == DOOM_FIRE_HEIGHT - 1) ? DOOM_FIRE_LAST_COLOR_ID : 0);
			cells[id].rgbUp();
		}
	}
}

function update(){
	let curId, belowId, newColorId;
	for(let row = 0; row < DOOM_FIRE_HEIGHT - 1; row++){
		for(let column = 0; column < DOOM_FIRE_WIDTH; column++){
			curId = column + (row * DOOM_FIRE_WIDTH);
			belowId = curId + DOOM_FIRE_WIDTH;

			newColorId = DOOM_FIRE_CELLS[belowId].rgbId - Math.floor(Math.random() * 3);
			if(newColorId < 0)
				newColorId = 0;

			DOOM_FIRE_CELLS[curId].rgbId = newColorId;
			DOOM_FIRE_CELLS[curId].rgbUp();
		}
	}
}

main();
