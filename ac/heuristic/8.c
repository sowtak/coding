#include <stdio.h>
#include <stdlib.h>

char op_map[9] = { '.', 'u', 'd', 'l', 'r', 'U', 'D', 'L', 'R' };
int d_map[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int mv_cnt[5] = { 1, 2, 3, 0, 2 };

int n = 0;
int p[20][3] = {};
int m = 0;
int h[10][2] = {};

int op[10] = {};

char in_str[4] = "";
char out_str[11] = "";

int area[32][32][3] = {};

int sim_p[20][3] = {};
int sim_h[10][2] = {};
int sim_op[10] = {};
int sim_area[32][32] = {};

long long abs_ll (long long a) {
  if (a < 0LL) {
    a = -a;
  }
  
  return a;
}

int cmp_score (long long *a, long long *b) {
  if (a[0]*(1LL<<b[1]) < b[0]*(1LL<<a[1])) {
    return -1;
  }
  if (a[0]*(1LL<<b[1]) > b[0]*(1LL<<a[1])) {
    return 1;
  }
  return 0;
}

long long expect_max_score (int *top_left, int *bottom_right, long long total_petcnt, long long pet_cnt) {
  int dir = 0;
  long long height = (long long) (bottom_right[0]-top_left[0]+1);
  long long width = (long long) (bottom_right[1]-top_left[1]+1);
  long long ans = height*width*(1LL<<(total_petcnt-pet_cnt));
  long long tmp = 0LL;
  
  int tmp_pos[2][2] = { { top_left[0], top_left[1] }, { bottom_right[0], bottom_right[1] } };
  
  if (pet_cnt <= 2LL || height < 5LL || width < 5LL) {
    return ans;
  }
  
  if (height > width) {
    tmp_pos[1][0] = top_left[0]+(bottom_right[0]-top_left[0])/2-1;
  } else {
    tmp_pos[1][1] = top_left[1]+(bottom_right[1]-top_left[1])/2-1;
  }
  
  tmp = expect_max_score(tmp_pos[0], tmp_pos[1], total_petcnt, pet_cnt/2LL);
  if (tmp > ans) {
    ans = tmp;
  }
  
  return ans;
}

void init_input () {
  int res = 0;
  res = scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    res = scanf("%d", p[i]);
    res = scanf("%d", p[i]+1);
    res = scanf("%d", p[i]+2);
    area[p[i][0]][p[i][1]][1]++;
  }
  res = scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    res = scanf("%d", h[i]);
    res = scanf("%d", h[i]+1);
    area[h[i][0]][h[i][1]][2]++;
  }
  for (int i = 0; i <= 31; i++) {
    area[0][i][0] = 1;
    area[31][i][0] = 1;
    area[i][0][0] = 1;
    area[i][31][0] = 1;
  }
  return;
}

void input_petmove (int cnt) {
  int res = 0;
  if (cnt > 0) {
    for (int i = 0; i < n; i++) {
      int idx = 0;
      res = scanf("%s", in_str);
      area[p[i][0]][p[i][1]][1]--;
      while (in_str[idx] != '\0') {
        for (int j = 0; j < 4; j++) {
          if (op_map[j+5] == in_str[idx]) {
            p[i][0] += d_map[j][0];
            p[i][1] += d_map[j][1];
          }
        }
        idx++;
      }
      area[p[i][0]][p[i][1]][1]++;
    }
  }
  
  return;
}

void reset_op () {
  for (int i = 0; i < m; i++) {
    op[i] = 0;
  }
  return;
}

void sim_reset_op () {
  for (int i = 0; i < m; i++) {
    sim_op[i] = 0;
  }
  return;
}

int output_op (int cnt) {
  for (int i = 0; i < m; i++) {
    out_str[i] = op_map[op[i]];
    if (op[i] > 4) {
      area[h[i][0]][h[i][1]][2]--;
      h[i][0] += d_map[op[i]-5][0];
      h[i][1] += d_map[op[i]-5][1];
      area[h[i][0]][h[i][1]][2]++;
    } else if (op[i] > 0) {
      area[h[i][0]+d_map[op[i]-1][0]][h[i][1]+d_map[op[i]-1][1]][0] = -1;
    }
  }
  out_str[m] = '\0';
  if (cnt > 0) {
    printf("%s\n", out_str);
    fflush(stdout);
    cnt--;
  }
  reset_op();
  
  return cnt;
}

void sim_output_op () {
  for (int i = 0; i < m; i++) {
    if (sim_op[i] > 4) {
      sim_h[i][0] += d_map[sim_op[i]-5][0];
      sim_h[i][1] += d_map[sim_op[i]-5][1];
    } else if (sim_op[i] > 0) {
      sim_area[sim_h[i][0]+d_map[sim_op[i]-1][0]][sim_h[i][1]+d_map[sim_op[i]-1][1]] = -1;
    }
  }
  
  sim_reset_op();
  
  return;
}

void sim_petmove_step () {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < mv_cnt[sim_p[i][2]-1]; j++) {
      int dest[4] = {};
      int dest_cnt = 0;
      int dir = 0;
      for (int k = 0; k < 4; k++) {
        if (sim_area[sim_p[i][0]+d_map[k][0]][sim_p[i][1]+d_map[k][1]] == 0) {
          dest[dest_cnt] = k;
          dest_cnt++;
        }
      }
      dir = rand()%dest_cnt;
      sim_p[i][0] += d_map[dest[dir]][0];
      sim_p[i][1] += d_map[dest[dir]][1];
    }
  }
  
  return;
}

void sim_petmove (int sim_cnt) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      sim_p[i][j] = p[i][j];
    }
  }
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      sim_area[i][j] = area[i][j][0];
    }
  }
  while (sim_cnt > 0) {
    sim_petmove_step();
    sim_cnt--;
  }
  
  return;
}

void sim_gather_all (int * pos) {
  int gather_num = 0;
  for (int i = 0; i < m; i++) {
    if (sim_h[i][0] == pos[0] && sim_h[i][1] == pos[1]) {
      gather_num++;
    }
  }
  while (gather_num < m) {
    for (int i = 0; i < m; i++) {
      int is_moved = 1;
      int dir = 0;
      if (sim_h[i][0] > pos[0] && sim_area[sim_h[i][0]-1][sim_h[i][1]] == 0) {
        dir = 0;
      } else if (sim_h[i][0] < pos[0] && sim_area[sim_h[i][0]+1][sim_h[i][1]] == 0) {
        dir = 1;
      } else if (sim_h[i][1] > pos[1] && sim_area[sim_h[i][0]][sim_h[i][1]-1] == 0) {
        dir = 2;
      } else if (sim_h[i][1] < pos[1] && sim_area[sim_h[i][0]][sim_h[i][1]+1] == 0) {
        dir = 3;
      } else {
        is_moved = 0;
      }
      if (is_moved > 0) {
        sim_h[i][0] += d_map[dir][0];
        sim_h[i][1] += d_map[dir][1];
        if (sim_h[i][0] == pos[0] && sim_h[i][1] == pos[1]) {
          gather_num++;
        }
      }
    }
    sim_petmove_step();
  }
  
  return;
}

void sim_set_op (int hidx, int hnum, int op_id) {
  for (int i = hidx; i < hidx+hnum; i++) {
    sim_op[i] = op_id;
  }
  return;
}

void sim_constr_wall (int hidx, int hnum, int dir, int s, int t, int *rem) {
  for (int i = hidx; i < hidx+hnum; i++) {
    if ((dir%2==0 && sim_h[i][dir/2] > s) || (dir%2==1 && sim_h[i][dir/2] < s)) {
      sim_op[i] = dir+5;
    } else {
      int target[2] = { sim_h[i][0]+d_map[dir^3][0], sim_h[i][1]+d_map[dir^3][1] };
      if (sim_area[target[0]][target[1]] == 0) {
        sim_area[target[0]][target[1]] = i+1;
      }
      if (sim_area[target[0]][target[1]] == i+1) {
        sim_op[i] = (dir^3)+1;
        *rem -= 1;
      } else if ((dir%2==0 && sim_h[i][dir/2] > t) || (dir%2==1 && sim_h[i][dir/2] < t)) {
        sim_op[i] = dir+5;
      } else {
        sim_op[i] = 0;
      }
    }
  }
  return;
}

void sim_div2 (int dir, int pos_div, int *top_left, int *bottom_right) {
  int pos[2] = {};
  int rem[2] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      sim_p[i][j] = p[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      sim_h[i][j] = h[i][j];
    }
  }
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      sim_area[i][j] = area[i][j][0];
    }
  }
  pos[dir] = top_left[dir];
  pos[dir] += (bottom_right[dir]-top_left[dir])/2;
  pos[1-dir] = pos_div;
  
  sim_gather_all(pos);
  
  sim_reset_op();
  sim_set_op(0, m/2, 2*(1-dir)+5);
  sim_set_op(m/2, m-m/2, 2*(1-dir)+6);
  sim_output_op();
  sim_petmove_step();
  
  rem[0] = pos[dir]-top_left[dir];
  rem[1] = bottom_right[dir]-pos[dir];
  while (rem[0] > 0 || rem[1] > 0) {
    sim_reset_op();
    sim_constr_wall(0, m/2, 2*dir, pos[dir]-1, top_left[dir], rem);
    sim_constr_wall(m/2, m-m/2, 2*dir+1, pos[dir]+1, bottom_right[dir], rem+1);
    sim_output_op();
    sim_petmove_step();
  }
  
  sim_gather_all(pos);
  
  return;
}

int noop (int cnt) {
  reset_op();
  cnt = output_op(cnt);
  input_petmove(cnt);
  return cnt;
}

int gather_all(int cnt, int *pos) {
  while (cnt > 0 && area[pos[0]][pos[1]][2] < m) {
    for (int i = 0; i < m; i++) {
      op[i] = 0;
      if (h[i][0] > pos[0] && area[h[i][0]-1][h[i][1]][0] == 0) {
        op[i] = 5;
      } else if (h[i][0] < pos[0] && area[h[i][0]+1][h[i][1]][0] == 0) {
        op[i] = 6;
      } else if (h[i][1] > pos[1] && area[h[i][0]][h[i][1]-1][0] == 0) {
        op[i] = 7;
      } else if (h[i][1] < pos[1] && area[h[i][0]][h[i][1]+1][0] == 0) {
        op[i] = 8;
      }
    }
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  
  return cnt;
}

void set_op (int hidx, int hnum, int op_id) {
  for (int i = hidx; i < hidx+hnum; i++) {
    op[i] = op_id;
  }
  return;
}

void constr_wall (int hidx, int hnum, int dir, int s, int t, int *rem) {
  for (int i = hidx; i < hidx+hnum; i++) {
    if ((dir%2==0 && h[i][dir/2] > s) || (dir%2==1 && h[i][dir/2] < s)) {
      op[i] = dir+5;
    } else {
      int target[2] = { h[i][0]+d_map[dir^3][0], h[i][1]+d_map[dir^3][1] };
      if (area[target[0]][target[1]][0] == 0) {
        area[target[0]][target[1]][0] = i+1;
      }
      if (area[target[0]][target[1]][0] == i+1) {
        int is_ok = 1;
        if (area[target[0]][target[1]][1] > 0) {
          is_ok = 0;
        }
        for (int j = 0; j < 4; j++) {
          if (area[target[0]+d_map[j][0]][target[1]+d_map[j][1]][1] > 0) {
            is_ok = 0;
          }
        }
        if (is_ok > 0) {
          op[i] = (dir^3)+1;
          *rem -= 1;
        } else {
          op[i] = 0;
        }
      } else if ((dir%2==0 && h[i][dir/2] > t) || (dir%2==1 && h[i][dir/2] < t)) {
        op[i] = dir+5;
      } else {
        op[i] = 0;
      }
    }
  }
  return;
}

int divide_into_2 (int cnt, int dir, int pos_div, int *top_left, int *bottom_right, long long total_pet) {
  int pos[2] = {};
  int rem[2] = {};
  long long pet_cnt = 0LL;
  int dir_chosen = 0;
  long long exp_score[2] = {};
  int tmp_pos[2] = {};
  pos[dir] = top_left[dir];
  pos[dir] += (bottom_right[dir]-top_left[dir])/2;
  pos[1-dir] = pos_div;
  cnt = gather_all(cnt, pos);
  reset_op();
  set_op(0, m/2, 2*(1-dir)+5);
  set_op(m/2, m-m/2, 2*(1-dir)+6);
  cnt = output_op(cnt);
  input_petmove(cnt);
  rem[0] = pos[dir]-top_left[dir];
  rem[1] = bottom_right[dir]-pos[dir];
  while (cnt > 0 && (rem[0] > 0 || rem[1] > 0)) {
    reset_op();
    constr_wall(0, m/2, 2*dir, pos[dir]-1, top_left[dir], rem);
    constr_wall(m/2, m-m/2, 2*dir+1, pos[dir]+1, bottom_right[dir], rem+1);
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  cnt = gather_all(cnt, pos);
  for (int i = 0; i < n; i++) {
    long long tmp = 1LL;
    if (p[i][dir] < top_left[dir]) {
      tmp = 0LL;
    }
    if (p[i][dir] > bottom_right[dir]) {
      tmp = 0LL;
    }
    if (p[i][1-dir] < top_left[1-dir]) {
      tmp = 0LL;
    }
    if (p[i][1-dir] > pos[1-dir]) {
      tmp = 0LL;
    }
    if (p[i][2] == 4) {
      tmp = 0LL;
    }
    pet_cnt += tmp;
  }
  tmp_pos[dir] = bottom_right[dir];
  tmp_pos[1-dir] = pos[1-dir]-1;
  exp_score[0] = expect_max_score(top_left, tmp_pos, total_pet, pet_cnt);
  tmp_pos[dir] = top_left[dir];
  tmp_pos[1-dir] = pos[1-dir]+1;
  exp_score[1] = expect_max_score(tmp_pos, bottom_right, total_pet, total_pet-pet_cnt);
  if (exp_score[0] > exp_score[1]) {
    dir_chosen = 2*(1-dir)+1;
    bottom_right[1-dir] = pos[1-dir]-1;
  } else {
    dir_chosen = 2*(1-dir);
    top_left[1-dir] = pos[1-dir]+1;
  }
  reset_op();
  set_op(0, m, (dir_chosen^1)+5);
  cnt = output_op(cnt);
  input_petmove(cnt);
  while (cnt > 0 && area[pos[0]][pos[1]][0] == 0) {
    int is_ok = 1;
    reset_op();
    if (area[pos[0]][pos[1]][1] > 0) {
      is_ok = 0;
    }
    for (int j = 0; j < 4; j++) {
      if (area[pos[0]+d_map[j][0]][pos[1]+d_map[j][1]][1] > 0) {
        is_ok = 0;
      }
    }
    if (is_ok > 0) {
      op[0] = dir_chosen+1;
    }
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  
  return cnt;
}

int divide_into_2_tmpscore (int cnt, int dir, int pos_div, int *top_left, int *bottom_right, long long total_pet, long long tmpscore) {
  int pos[2] = {};
  int rem[2] = {};
  long long pet_cnt = 0LL;
  int dir_chosen = 0;
  long long exp_score[2] = {};
  int tmp_pos[2] = {};
  pos[dir] = top_left[dir];
  pos[dir] += (bottom_right[dir]-top_left[dir])/2;
  pos[1-dir] = pos_div;
  cnt = gather_all(cnt, pos);
  reset_op();
  set_op(0, m/2, 2*(1-dir)+5);
  set_op(m/2, m-m/2, 2*(1-dir)+6);
  cnt = output_op(cnt);
  input_petmove(cnt);
  rem[0] = pos[dir]-top_left[dir];
  rem[1] = bottom_right[dir]-pos[dir];
  while (cnt > 0 && (rem[0] > 0 || rem[1] > 0)) {
    reset_op();
    constr_wall(0, m/2, 2*dir, pos[dir]-1, top_left[dir], rem);
    constr_wall(m/2, m-m/2, 2*dir+1, pos[dir]+1, bottom_right[dir], rem+1);
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  cnt = gather_all(cnt, pos);
  for (int i = 0; i < n; i++) {
    long long tmp = 1LL;
    if (p[i][dir] < top_left[dir]) {
      tmp = 0LL;
    }
    if (p[i][dir] > bottom_right[dir]) {
      tmp = 0LL;
    }
    if (p[i][1-dir] < top_left[1-dir]) {
      tmp = 0LL;
    }
    if (p[i][1-dir] > pos[1-dir]) {
      tmp = 0LL;
    }
    if (p[i][2] == 4) {
      tmp = 0LL;
    }
    pet_cnt += tmp;
  }
  tmp_pos[dir] = bottom_right[dir];
  tmp_pos[1-dir] = pos[1-dir]-1;
  exp_score[0] = expect_max_score(top_left, tmp_pos, total_pet, pet_cnt);
  tmp_pos[dir] = top_left[dir];
  tmp_pos[1-dir] = pos[1-dir]+1;
  exp_score[1] = expect_max_score(tmp_pos, bottom_right, total_pet, total_pet-pet_cnt);
  if (tmpscore >= exp_score[0] && tmpscore >= exp_score[1]) {
    return cnt;
  }
  if (exp_score[0] > exp_score[1]) {
    dir_chosen = 2*(1-dir)+1;
    bottom_right[1-dir] = pos[1-dir]-1;
  } else {
    dir_chosen = 2*(1-dir);
    top_left[1-dir] = pos[1-dir]+1;
  }
  reset_op();
  set_op(0, m, (dir_chosen^1)+5);
  cnt = output_op(cnt);
  input_petmove(cnt);
  while (cnt > 0 && area[pos[0]][pos[1]][0] == 0) {
    int is_ok = 1;
    reset_op();
    if (area[pos[0]][pos[1]][1] > 0) {
      is_ok = 0;
    }
    for (int j = 0; j < 4; j++) {
      if (area[pos[0]+d_map[j][0]][pos[1]+d_map[j][1]][1] > 0) {
        is_ok = 0;
      }
    }
    if (is_ok > 0) {
      op[0] = dir_chosen+1;
    }
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  
  return cnt;
}

int dog_distr_2 (int cnt, int dir, int pos_div, int *top_left, int *bottom_right, long long total_pet) {
  int pos[2] = {};
  int rem[2] = {};
  long long pet_cnt = 0LL;
  int dir_chosen = 0;
  int is_end = 0;
  int is_fin = 0;
  pos[dir] = top_left[dir];
  pos[dir] += (bottom_right[dir]-top_left[dir])/2;;
  pos[1-dir] = pos_div;
  cnt = gather_all(cnt, pos);
  reset_op();
  set_op(0, m/2, 2*(1-dir)+5);
  set_op(m/2, m-m/2, 2*(1-dir)+6);
  cnt = output_op(cnt);
  input_petmove(cnt);
  rem[0] = pos[dir]-top_left[dir];
  rem[1] = bottom_right[dir]-pos[dir];
  while (cnt > 0 && (rem[0] > 0 || rem[1] > 0)) {
    reset_op();
    constr_wall(0, m/2, 2*dir, pos[dir]-1, top_left[dir], rem);
    constr_wall(m/2, m-m/2, 2*dir+1, pos[dir]+1, bottom_right[dir], rem+1);
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  cnt = gather_all(cnt, pos);
  
  reset_op();
  set_op(0, m/2, 2*(1-dir)+5);
  set_op(m/2, m-m/2, 2*(1-dir)+6);
  cnt = output_op(cnt);
  input_petmove(cnt);
  
  while (cnt > 0 && is_end <= 0) {
    is_end = 1;
    reset_op();
    if (h[0][1-dir] > top_left[1-dir]) {
      set_op(0, m/2, 2*(1-dir)+5);
      is_end = 0;
    }
    if (h[m/2][1-dir] < bottom_right[1-dir]) {
      set_op(m/2, m-m/2-1, 2*(1-dir)+6);
      is_end = 0;
    }
    if (is_end <= 0) {
      cnt = output_op(cnt);
      input_petmove(cnt);
    }
  }
  
  while (cnt > 0 && is_fin <= 0) {
    reset_op();
    for (int i = 0; i < n; i++) {
      long long tmp = 1LL;
      if (p[i][dir] < top_left[dir]) {
        tmp = 0LL;
      }
      if (p[i][dir] > bottom_right[dir]) {
        tmp = 0LL;
      }
      if (p[i][1-dir] < top_left[1-dir]) {
        tmp = 0LL;
      }
      if (p[i][1-dir] > pos[1-dir]) {
        tmp = 0LL;
      }
      pet_cnt += tmp;
    }
    if (abs_ll(total_pet-2LL*pet_cnt) > 1LL) {
      int is_ok = 1;
      if (area[pos[0]][pos[1]][1] > 0) {
        is_ok = 0;
      }
      for (int j = 0; j < 4; j++) {
        if (area[pos[0]+d_map[j][0]][pos[1]+d_map[j][1]][1] > 0) {
          is_ok = 0;
        }
      }
      if (is_ok > 0) {
        op[m-1] = 2*(1-dir)+1;
        is_fin = 1;
      }
    }
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  
  return cnt;
}

int divide_into_4 (int cnt, int *pos, int *top_left, int *bottom_right) {
  int rem[4] = {};
  long long pet_cnt[4] = {};
  long long max[2] = { 0LL, 20LL };
  int argmin = 0;
  int div_op[4] = {};
  int is_fin = 0;
  int room_size[4] = {};
  cnt = gather_all(cnt, pos);
  reset_op();
  set_op(0, m/4, 5);
  set_op(m/4, m/4, 6);
  set_op(2*(m/4), m/4, 7);
  set_op(3*(m/4), m-3*(m/4), 8);
  cnt = output_op(cnt);
  input_petmove(cnt);
  rem[0] = pos[1]-top_left[1]-1;
  rem[1] = bottom_right[1]-pos[1]-1;
  rem[2] = pos[0]-top_left[0]-1;
  rem[3] = bottom_right[0]-pos[0]-1;
  while (cnt > 0 && (rem[0] > 0 || rem[1] > 0 || rem[2] > 0 || rem[3] > 0)) {
    reset_op();
    constr_wall(0, m/4, 2, pos[1]-2, top_left[1], rem);
    constr_wall(m/4, m/4, 3, pos[1]+2, bottom_right[1], rem+1);
    constr_wall(2*(m/4), m/4, 0, pos[0]-2, top_left[0], rem+2);
    constr_wall(3*(m/4), m-3*(m/4), 1, pos[0]+2, bottom_right[0], rem+3);
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  cnt = gather_all(cnt, pos);
  for (int i = 0; i < n; i++) {
    if (p[i][2] != 4 && p[i][0] >= top_left[0] && p[i][1] >= top_left[1] && p[i][0] <= bottom_right[0] && p[i][1] <= bottom_right[1]) {
      if (p[i][0] < pos[0]) {
        if (p[i][1] < pos[1]) {
          pet_cnt[0] += 1LL;
        } else {
          pet_cnt[1] += 1LL;
        }
      } else {
        if (p[i][1] < pos[1]) {
          pet_cnt[2] += 1LL;
        } else {
          pet_cnt[3] += 1LL;
        }
      }
    }
  }
  
  room_size[0] = (pos[0]-top_left[0])*(pos[1]-top_left[1]);
  room_size[1] = (pos[0]-top_left[0])*(bottom_right[1]-pos[1]);
  room_size[2] = (bottom_right[0]-pos[0])*(pos[1]-top_left[1]);
  room_size[3] = (bottom_right[0]-pos[0])*(bottom_right[1]-pos[1]);
  
  for (int i = 0; i < 4; i++) {
    long long tmp[2] = { (long long)room_size[i], pet_cnt[i] };
    if (cmp_score(tmp, max) > 0) {
      max[0] = tmp[0];
      max[1] = tmp[1];
      argmin = i;
    }
  }
  
  if (argmin == 0) {
    div_op[0] = 5;
    div_op[1] = 7;
    div_op[2] = 2;
    div_op[3] = 4;
  } else if (argmin == 1) {
    div_op[0] = 5;
    div_op[1] = 8;
    div_op[2] = 2;
    div_op[3] = 3;
  } else if (argmin == 2) {
    div_op[0] = 6;
    div_op[1] = 7;
    div_op[2] = 1;
    div_op[3] = 4;
  } else {
    div_op[0] = 6;
    div_op[1] = 8;
    div_op[2] = 1;
    div_op[3] = 3;
  }
  
  reset_op();
  set_op(0, m, div_op[0]);
  cnt = output_op(cnt);
  input_petmove(cnt);
  reset_op();
  set_op(0, m, div_op[1]);
  cnt = output_op(cnt);
  input_petmove(cnt);
  
  while (cnt > 0 && is_fin <= 0) {
    is_fin = 1;
    reset_op();
    for (int i = 0; i < 2; i++) {
      int is_ok = 1;
      int pos[2] = { h[i][0]+d_map[div_op[i+2]-1][0], h[i][1]+d_map[div_op[i+2]-1][1] };
      if (area[pos[0]][pos[1]][1] > 0) {
        is_ok = 0;
      }
      for (int j = 0; j < 4; j++) {
        if (area[pos[0]+d_map[j][0]][pos[1]+d_map[j][1]][1] > 0) {
          is_ok = 0;
        }
      }
      if (is_ok > 0 && area[pos[0]][pos[1]][0] >= 0) {
        op[i] = div_op[i+2];
      } else if (area[pos[0]][pos[1]][0] >= 0) {
        is_fin = 0;
      }
    }
    cnt = output_op(cnt);
    input_petmove(cnt);
  }
  
  return cnt;
}

int half (int cnt) {
  int top_left[2] = { 1, 1 };
  int bottom_right[2] = { 30, 30 };
  return divide_into_2(cnt, 0, 15, top_left, bottom_right, (long long)n);
}

int half_half (int cnt) {
  int top_left[2] = { 1, 1 };
  int bottom_right[2] = { 30, 30 };
  long long pet_cnt = 0LL;
  cnt = divide_into_2(cnt, 0, 15, top_left, bottom_right, (long long)n);
  for (int i = 0; i < n; i++) {
    long long tmp = 1LL;
    for (int j = 0; j < 2; j++) {
      if (p[i][j] < top_left[j]) {
        tmp = 0LL;
      }
      if (p[i][j] > bottom_right[j]) {
        tmp = 0LL;
      }
    }
    pet_cnt += tmp;
  }
  return divide_into_2(cnt, 1, 15, top_left, bottom_right, pet_cnt);
}

int half_rec (int cnt, int sim_times, int sim_times_div2) {
  int top_left[2] = { 1, 1 };
  int bottom_right[2] = { 30, 30 };
  long long pet_cnt = (long long)n;
  long long dog_cnt = 0LL;
  int dir = 0;
  long long tmp_score = 0LL;
  long long total_petcnt = 0LL;
  int is_fin = 0;
  while (cnt > 0 && pet_cnt-dog_cnt > 2LL && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4) {
    int pos_div = top_left[1-dir];
    pos_div += (bottom_right[1-dir]-top_left[1-dir])/2;
    cnt = divide_into_2(cnt, dir, pos_div, top_left, bottom_right, pet_cnt-dog_cnt);
    pet_cnt = 0LL;
    dog_cnt = 0LL;
    for (int i = 0; i < n; i++) {
      long long tmp = 1LL;
      for (int j = 0; j < 2; j++) {
        if (p[i][j] < top_left[j]) {
          tmp = 0LL;
        }
        if (p[i][j] > bottom_right[j]) {
          tmp = 0LL;
        }
      }
      pet_cnt += tmp;
      if (p[i][2] == 4) {
        dog_cnt += tmp;
      }
    }
    dir = 1-dir;
  }
  tmp_score = (long long) ((bottom_right[0]-top_left[0]+1)*(bottom_right[1]-top_left[1]+1));
  total_petcnt = pet_cnt-dog_cnt;
  if (cnt > 0 && pet_cnt-dog_cnt > 1LL && dog_cnt < 2LL && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4) {
    int dir = 0;
    int pos_div = 0;
    long long exp_score[2][30][2] = {};
    long long max_score = 0LL;
    int sim_cnt = 3*(bottom_right[0]-top_left[0]+bottom_right[1]-top_left[1])/2;
    for (int t = 0; t < sim_times; t++) {
      sim_petmove(sim_cnt);
      for (int i = 0; i < 2; i++) {
        for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
          long long tmp_pet_cnt = 0LL;
          long long tmp_score = 0LL;
          int tmp_pos[2] = {};
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > j) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < top_left[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = bottom_right[i];
          tmp_pos[1-i] = j-1;
          tmp_score = expect_max_score(top_left, tmp_pos, total_petcnt, tmp_pet_cnt);
          exp_score[i][j][0] += tmp_score;
          tmp_pet_cnt = 0LL;
          tmp_score = 0LL;
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > bottom_right[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < j) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = top_left[i];
          tmp_pos[1-i] = j+1;
          tmp_score = expect_max_score(tmp_pos, bottom_right, total_petcnt, tmp_pet_cnt);
          exp_score[i][j][1] += tmp_score;
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
        for (int k = 0; k < 2; k++) {
          if (max_score < exp_score[i][j][k]) {
            max_score = exp_score[i][j][k];
            dir = i;
            pos_div = j;
          }
        }
      }
    }
    if (max_score > tmp_score*((long long) sim_times)) {
      cnt = divide_into_2(cnt, dir, pos_div, top_left, bottom_right, pet_cnt-dog_cnt);
    }
    pet_cnt = 0LL;
    dog_cnt = 0LL;
    for (int i = 0; i < n; i++) {
      long long tmp = 1LL;
      for (int j = 0; j < 2; j++) {
        if (p[i][j] < top_left[j]) {
          tmp = 0LL;
        }
        if (p[i][j] > bottom_right[j]) {
          tmp = 0LL;
        }
      }
      pet_cnt += tmp;
      if (p[i][2] == 4) {
        dog_cnt += tmp;
      }
    }
  }
  tmp_score = (long long) ((bottom_right[0]-top_left[0]+1)*(bottom_right[1]-top_left[1]+1));
  total_petcnt = pet_cnt-dog_cnt;
  if (cnt > 0 && pet_cnt-dog_cnt > 0LL && dog_cnt < 2LL && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4) {
    int dir = 0;
    int pos_div = 0;
    long long exp_score[2][30][2] = {};
    long long max_score = 0LL;
    for (int i = 0; i < 2; i++) {
      for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
        for (int t = 0; t < sim_times_div2; t++) {
          long long tmp_pet_cnt = 0LL;
          long long tmp_score = 0LL;
          int tmp_pos[2] = {};
          sim_div2(i, j, top_left, bottom_right);
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > j) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < top_left[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = bottom_right[i];
          tmp_pos[1-i] = j-1;
          tmp_score = expect_max_score(top_left, tmp_pos, total_petcnt, tmp_pet_cnt);
          exp_score[i][j][0] += tmp_score;
          tmp_pet_cnt = 0LL;
          tmp_score = 0LL;
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > bottom_right[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < j) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = top_left[i];
          tmp_pos[1-i] = j+1;
          tmp_score = expect_max_score(tmp_pos, bottom_right, total_petcnt, tmp_pet_cnt);
          exp_score[i][j][1] += tmp_score;
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
        for (int k = 0; k < 2; k++) {
          if (max_score < exp_score[i][j][k]) {
            max_score = exp_score[i][j][k];
            dir = i;
            pos_div = j;
          }
        }
      }
    }
    if (max_score > 15LL*tmp_score*((long long) sim_times_div2)/10LL) {
      cnt = divide_into_2_tmpscore(cnt, dir, pos_div, top_left, bottom_right, pet_cnt-dog_cnt, tmp_score);
    }
    if (top_left[1-dir] < pos_div && pos_div < bottom_right[1-dir]) {
      is_fin = 1;
    }
    pet_cnt = 0LL;
    dog_cnt = 0LL;
    for (int i = 0; i < n; i++) {
      long long tmp = 1LL;
      for (int j = 0; j < 2; j++) {
        if (p[i][j] < top_left[j]) {
          tmp = 0LL;
        }
        if (p[i][j] > bottom_right[j]) {
          tmp = 0LL;
        }
      }
      pet_cnt += tmp;
      if (p[i][2] == 4) {
        dog_cnt += tmp;
      }
    }
  }
  if ((pet_cnt > 2LL || dog_cnt > 1LL) && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4 && is_fin <= 0) {
    int pos_div = top_left[1-dir];
    pos_div += (bottom_right[1-dir]-top_left[1-dir])/2;
    cnt = dog_distr_2(cnt, dir, pos_div, top_left, bottom_right, pet_cnt);
  }
  
  return cnt;
}

int quater (int cnt) {
  int top_left[2] = { 1, 1 };
  int bottom_right[2] = { 30, 30 };
  int pos[2] = { 15, 15 };
  return divide_into_4(cnt, pos, top_left, bottom_right);
}

int half_sim_rec (int cnt, int sim_times) {
  int top_left[2] = { 1, 1 };
  int bottom_right[2] = { 30, 30 };
  long long pet_cnt = (long long)n;
  long long dog_cnt = 0LL;
  long long tmp_score = (long long) ((bottom_right[0]-top_left[0]+1)*(bottom_right[1]-top_left[1]+1));
  long long total_petcnt = 0LL;
  int is_fin = 0;
  for (int i = 0; i < n; i++) {
    if (p[i][2] == 4) {
      dog_cnt += 1LL;
    }
  }
  total_petcnt = pet_cnt-dog_cnt;
  while (cnt > 0 && pet_cnt-dog_cnt > 0LL && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4 && is_fin <= 0) {
    int dir = 0;
    int pos_div = 0;
    long long mul = 0LL;
    long long exp_score[2][30][3] = {};
    long long max_score = 0LL;
    int sim_cnt = 3*(bottom_right[0]-top_left[0]+bottom_right[1]-top_left[1])/2; 
    for (int t = 0; t < sim_times; t++) {
      sim_petmove(sim_cnt);
      for (int i = 0; i < 2; i++) {
        int center = top_left[1-i]+(bottom_right[1-i]-top_left[1-i])/2;
        for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
          long long tmp_pet_cnt = 0LL;
          long long tmp_score = 0LL;
          long long mul = (long long) (center-top_left[1-i]);
          int tmp_pos[2] = {};
          mul -= abs_ll((long long)(center-j));
          mul *= mul;
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > j) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < top_left[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = bottom_right[i];
          tmp_pos[1-i] = j-1;
          tmp_score = expect_max_score(top_left, tmp_pos, total_petcnt, tmp_pet_cnt);
          tmp_score *= mul;
          exp_score[i][j][0] += tmp_score;
          tmp_pet_cnt = 0LL;
          tmp_score = 0LL;
          for (int k = 0; k < n; k++) {
            long long tmp = 1LL;
            if (sim_p[k][1-i] > bottom_right[1-i]) {
              tmp = 0LL;
            }
            if (sim_p[k][1-i] < j) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > bottom_right[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][i] > top_left[i]) {
              tmp = 0LL;
            }
            if (sim_p[k][2] == 4) {
              tmp = 0LL;
            }
            tmp_pet_cnt += tmp;
          }
          tmp_pos[i] = top_left[i];
          tmp_pos[1-i] = j+1;
          tmp_score = expect_max_score(tmp_pos, bottom_right, total_petcnt, tmp_pet_cnt);
          tmp_score *= mul;
          exp_score[i][j][1] += tmp_score;
          exp_score[i][j][2] = mul;
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = top_left[1-i]+2; j < bottom_right[1-i]-1; j++) {
        for (int k = 0; k < 2; k++) {
          if (max_score < exp_score[i][j][k]) {
            max_score = exp_score[i][j][k];
            dir = i;
            pos_div = j;
            mul = exp_score[i][j][2];
          }
        }
      }
    }
    if (max_score > mul*tmp_score*((long long) sim_times)) {
      cnt = divide_into_2(cnt, dir, pos_div, top_left, bottom_right, pet_cnt-dog_cnt);
    } else {
      is_fin = 1;
    }
    pet_cnt = 0LL;
    dog_cnt = 0LL;
    for (int i = 0; i < n; i++) {
      long long tmp = 1LL;
      for (int j = 0; j < 2; j++) {
        if (p[i][j] < top_left[j]) {
          tmp = 0LL;
        }
        if (p[i][j] > bottom_right[j]) {
          tmp = 0LL;
        }
      }
      pet_cnt += tmp;
      if (p[i][2] == 4) {
        dog_cnt += tmp;
      }
    }
    tmp_score = (long long) ((bottom_right[0]-top_left[0]+1)*(bottom_right[1]-top_left[1]+1));
    tmp_score *= (1LL<<(total_petcnt-pet_cnt+dog_cnt));
  }
  if ((pet_cnt > 2LL || dog_cnt > 1LL) && bottom_right[0]-top_left[0] > 4 && bottom_right[1]-top_left[1] > 4) {
    int pos_div = top_left[1];
    pos_div += (bottom_right[1]-top_left[1])/2;
    cnt = dog_distr_2(cnt, 0, pos_div, top_left, bottom_right, pet_cnt);
  }
  
  return cnt;
}

int main () {
  int cnt = 300;
  srand(1);
  init_input();
  cnt = half_rec(cnt, 4000, 2000);
  while (cnt > 0) {
    cnt = noop(cnt);
  }
  return 0;
}
