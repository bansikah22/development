// src/app/item-list/item-list.component.ts
import { Component } from '@angular/core';

@Component({
  selector: 'app-item-list', // This should match the tag used in the template
  templateUrl: './item-list.component.html',
  styleUrls: ['./item-list.component.css']
})
export class ItemListComponent {
  items: string[] = ['Item 1', 'Item 2', 'Item 3'];
}