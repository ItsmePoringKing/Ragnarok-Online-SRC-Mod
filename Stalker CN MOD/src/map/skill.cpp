// Define the skill function for Create Nugget
int skill_create_nugget(struct map_session_data *sd, struct block_list *bl, int skill_id, int skill_lv, uint16 flag)
{
    int range = 5; // Adjust as needed
    int skill_range = skill_get_range(skill_id, skill_lv);

    // Check if the skill is in range
    if (distance_bl(sd, bl) > range) {
        clif_skill_fail(sd, skill_id, USESKILL_FAIL_OUT_OF_RANGE, 0);
        return 0;
    }

    // Check if the target is valid
    if (!bl) {
        clif_skill_fail(sd, skill_id, USESKILL_FAIL_INVALID_TARGET, 0);
        return 0;
    }

    // Move the player to the target's cell
    if (bl->type == BL_PC || bl->type == BL_MOB) {
        sd->bl.x = bl->x;
        sd->bl.y = bl->y;
        map_foreachinmap(clif_updatestate, sd->bl.m, BL_PC, &sd->bl, 1);
    }

    return 1;
}


//Find the skill_castend_damage_id function.
//Add a case for your new skill. add the code below
case <SKILL_ID>: // Replace <SKILL_ID> with the actual skill ID you will use
    skill_create_nugget(sd, bl, skill_id, skill_lv, flag);
    break;
